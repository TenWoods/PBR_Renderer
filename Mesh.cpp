#include "Mesh.h"
#include "Render.h"
#include <iostream>
#include "stb_image.h"

Mesh::Mesh() : VAO(0), VBO(0), EBO(0)
{

}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, Render* window) : RenderObject(),
	m_window(window), m_vertices(vertices), m_indices(indices)
{
	m_textures = textures;
	//std::cout << m_vertices.size() << " " << m_indices.size() << std::endl;
	SetupMesh();
	isFirst = true;
}

void Mesh::SetupMesh()
{
	m_window->glGenVertexArrays(1, &VAO);
	m_window->glGenBuffers(1, &VBO);
	m_window->glGenBuffers(1, &EBO);
	m_window->glBindVertexArray(VAO);
	m_window->glBindBuffer(GL_ARRAY_BUFFER, VBO);
	m_window->glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);
	m_window->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	m_window->glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);

	m_window->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	m_window->glEnableVertexAttribArray(0);

	m_window->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	m_window->glEnableVertexAttribArray(1);

	//m_window->glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
	//m_window->glEnableVertexAttribArray(2);

	m_window->glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
	m_window->glEnableVertexAttribArray(3);

	m_window->glBindVertexArray(0);
	//for (int i = 0; i < m_indices.size(); i++)
	//{
	//	std::cout << m_indices[i] << std::endl;
	//}
}

void Mesh::Draw(QOpenGLShaderProgram* shader)
{
	shader->bind();
	m_window->glBindVertexArray(VAO);
	int index = 3;
	for (unsigned int i = 0; i < m_textures.size(); i++)
	{
		switch (m_textures[i].type)
		{
		case TEXTURE_TYPE::DIFFUSE :
			shader->setUniformValue("material.texture_diffuse", index);
		/*	if (isFirst)
			{
				std::cout << textures[i].path << std::endl;
			}*/
			break;
		case TEXTURE_TYPE::NORMAL :
			shader->setUniformValue("material.texture_normal", index);
		/*	if (isFirst)
			{
				std::cout << textures[i].path << std::endl;
			}*/
			break;
		case TEXTURE_TYPE::SPECULAR :
			shader->setUniformValue("material.texture_specular", index);
			//if (isFirst)
			//{
			//	std::cout << textures[i].path << std::endl;
			//}
			break;
		case TEXTURE_TYPE::HEIGHT :
			shader->setUniformValue("material.texture_height", index);
		/*	if (isFirst)
			{
				std::cout << textures[i].path << std::endl;
			}*/
			break;
		case TEXTURE_TYPE::AO :
			shader->setUniformValue("material.texture_ao", index);
		/*	if (isFirst)
			{
				std::cout << textures[i].path << std::endl;
			}*/
			break;
		case TEXTURE_TYPE::METALLIC :
			shader->setUniformValue("material.texture_metallic", index);
		/*	if (isFirst)
			{
				std::cout << textures[i].path << std::endl;
			}*/
			break;
		case TEXTURE_TYPE::ROUGHNESS:
			shader->setUniformValue("material.texture_roughness", index);
	/*		if (isFirst)
			{
				std::cout << textures[i].path << std::endl;
			}*/
			break;
		default:
			break;
		}
		m_window->glActiveTexture(GL_TEXTURE0 + index);
		m_window->glBindTexture(GL_TEXTURE_2D, m_textures[i].id);
		index++;
		//if (isFirst)
		//{
		//	std::cout << textures[i].path << std::endl;
		//}
	}
	isFirst = false;
	m_window->glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
	//m_window->glDrawArrays(GL_TRIANGLES, 0, sizeof(m_vertices));
	shader->release();
	m_window->glActiveTexture(GL_TEXTURE0);
}

void Mesh::AddTexture(std::string path, TEXTURE_TYPE type)
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
		m_textures.push_back(texture);
	}
	else
	{
		qDebug() << "load texture error";
	}
	stbi_image_free(data);
	m_window->glBindTexture(GL_TEXTURE_2D, 0);
}