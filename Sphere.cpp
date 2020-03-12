#include "Sphere.h"
#include "Render.h"
#include "stb_image.h"

Sphere::Sphere() : RenderObject()
{

}

Sphere::Sphere(QVector3D position, QVector3D scale, QVector3D rotation, Render* window) : RenderObject(position, scale, rotation, window)
{
	const unsigned int segmentX = 64;
	const unsigned int segmentY = 64;
	const float PI = 3.14159265359;

	std::vector<QVector3D> positions;
	std::vector<QVector3D> normals;
	std::vector<QVector2D> texcoords;
	std::vector<unsigned int> indices;
	//生成球数据
	for (int y = 0; y <= segmentY; y++)
	{
		for (int x = 0; x <= segmentX; x++)
		{
			float deltaX = (float)x / (float)segmentX;
			float deltaY = (float)y / (float)segmentY;
			float posX = std::sin(deltaY * PI) * std::cos(deltaX * 2.0f * PI);
			float posY = std::cos(deltaY * PI);
			float posZ = std::sin(deltaY * PI) * std::sin(deltaX * 2.0f * PI);
			positions.push_back(QVector3D(posX, posY, posZ));
			texcoords.push_back(QVector2D(deltaX, deltaY));
			normals.push_back(QVector3D(posX, posY, posZ));
		}
	}

	for (int i = 0; i < segmentY; i++)
	{
		for (int j = 0; j < segmentX; j++)
		{

			indices.push_back(i * (segmentX + 1) + j);
			indices.push_back((i + 1) * (segmentX + 1) + j);
			indices.push_back((i + 1) * (segmentX + 1) + j + 1);

			indices.push_back(i * (segmentX + 1) + j);
			indices.push_back((i + 1) * (segmentX + 1) + j + 1);
			indices.push_back(i * (segmentX + 1) + j + 1);
		}
	}

	/*bool oddRow = false;
	for (int y = 0; y < segmentY; y++)
	{
		if (!oddRow)
		{
			for (int x = 0; x <= segmentX; x++)
			{
				indices.push_back(y * (segmentX + 1) + x);
				indices.push_back((y + 1) * (segmentX + 1) + x);
			}
		}
		else
		{
			for (int x = segmentX; x >= 0; x--)
			{
				indices.push_back((y + 1) * (segmentX + 1) + x);
				indices.push_back(y * (segmentX + 1) + x);
			}
		}
		oddRow = !oddRow;
	}*/
	indexCount = indices.size();

	std::vector<float> data;
	for (int i = 0; i < positions.size(); i++)
	{
		data.push_back(positions[i].x());
		data.push_back(positions[i].y());
		data.push_back(positions[i].z());
		data.push_back(normals[i].x());
		data.push_back(normals[i].y());
		data.push_back(normals[i].z());
		data.push_back(texcoords[i].x());
		data.push_back(texcoords[i].y());
	}

	m_window->glGenVertexArrays(1, &VAO);
	m_window->glGenBuffers(1, &VBO);
	m_window->glGenBuffers(1, &EBO);
	m_window->glBindVertexArray(VAO);
	m_window->glBindBuffer(GL_ARRAY_BUFFER, VBO);
	m_window->glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), &data[0], GL_STATIC_DRAW);
	m_window->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	m_window->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);

	m_window->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 8, (void*)0);
	m_window->glEnableVertexAttribArray(0);
	m_window->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 8, (void*)(sizeof(GL_FLOAT) * 3));
	m_window->glEnableVertexAttribArray(1);
	m_window->glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(GL_FLOAT) * 8, (void*)(sizeof(GL_FLOAT) * 6));
	m_window->glEnableVertexAttribArray(3);
}

void Sphere::Draw(QOpenGLShaderProgram* shader)
{
	shader->bind();
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		switch (textures[i].type)
		{
		case TEXTURE_TYPE::DIFFUSE:
			shader->setUniformValue("material.texture_diffuse", i);
			break;
		case TEXTURE_TYPE::SPECULAR:
			shader->setUniformValue("material.texture_specular", i);
			break;
		case TEXTURE_TYPE::NORMAL:
			shader->setUniformValue("material.texture_normal", i);
			break;
		case TEXTURE_TYPE::HEIGHT:
			shader->setUniformValue("material.texture_height", i);
			break;
		default:
			break;
		}
		m_window->glActiveTexture(GL_TEXTURE0 + i);
		m_window->glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}

	QMatrix4x4 model;
	model.translate(m_position);
	model.scale(m_scale);
	//TODO: 旋转和放缩的添加
	shader->setUniformValue("model", model);
	QMatrix4x4 view;
	view = m_window->camera.ViewMatrix();
	shader->setUniformValue("view", view);
	QMatrix4x4 projection;
	projection.perspective(m_window->camera.get_zoom(), (float)m_window->width() / (float)m_window->height(), 0.1f, 100.0f);
	shader->setUniformValue("projection", projection);
	m_window->glBindVertexArray(VAO);
	m_window->glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	shader->release();
}

void Sphere::AddTexture(std::string path, TEXTURE_TYPE type)
{
	unsigned int tex;
	m_window->glGenTextures(1, &tex);
	m_window->glBindTexture(GL_TEXTURE_2D, tex);
	m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	m_window->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, channel;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &channel, 0);
	if (data)
	{
		GLenum format = GL_RED;
		if (channel == 1)
		{
			format = GL_RED;
		}
		else if (channel == 3)
		{
			format = GL_RGB;
		}
		else if (channel == 4)
		{
			format = GL_RGBA;
		}
		m_window->glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		m_window->glGenerateMipmap(GL_TEXTURE_2D);
		Texture texture = { tex, type, path };
		textures.push_back(texture);
	}
	else
	{
		qDebug() << "load texture error";
	}
	stbi_image_free(data);
	m_window->glBindTexture(GL_TEXTURE_2D, 0);
}