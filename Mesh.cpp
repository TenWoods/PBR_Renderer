#include "Mesh.h"
#include "Render.h"

Mesh::Mesh() : VAO(0), VBO(0), EBO(0)
{

}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, Render* window) : m_window(window)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;
	SetupMesh();
}

void Mesh::SetupMesh()
{
	m_window->glGenVertexArrays(1, &VAO);
	m_window->glGenBuffers(1, &VBO);
	m_window->glGenBuffers(1, &EBO);
	m_window->glBindVertexArray(VAO);
	m_window->glBindBuffer(GL_ARRAY_BUFFER, VBO);
	m_window->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	m_window->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	m_window->glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices), &indices[0], GL_STATIC_DRAW);
	m_window->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	m_window->glEnableVertexAttribArray(0);
	m_window->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	m_window->glEnableVertexAttribArray(1);
	m_window->glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tangent));
	m_window->glEnableVertexAttribArray(2);
	m_window->glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoord));
	m_window->glEnableVertexAttribArray(3);
	m_window->glBindVertexArray(0);
}

void Mesh::Draw(QOpenGLShaderProgram* shader)
{
	shader->bind();
	m_window->glBindVertexArray(VAO);
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		switch (textures[i].type)
		{
		case TEXTURE_TYPE::DIFFUSE :
			shader->setUniformValue("material.texture_diffuse", i);
			break;
		case TEXTURE_TYPE::NORMAL :
			shader->setUniformValue("material.texture_normal", i);
			break;
		case TEXTURE_TYPE::SPECULAR :
			shader->setUniformValue("material.texture_specular", i);
			break;
		case TEXTURE_TYPE::HEIGHT :
			shader->setUniformValue("material.texture_height", i);
			break;
		default:
			break;
		}
		m_window->glActiveTexture(GL_TEXTURE0 + i);
		m_window->glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}
	m_window->glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	shader->release();
	m_window->glActiveTexture(GL_TEXTURE0);
}