#pragma once
#include <qopenglshaderprogram.h>
#include "RenderObject.h"

class Mesh
{
private :
	std::vector<Vertex> m_vertices;
	std::vector<Texture> m_textures;
	std::vector<unsigned int> m_indices;
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	Render* m_window;
	void SetupMesh();
public :
	Mesh();
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, Render* window);
	void Draw(QOpenGLShaderProgram* shader);
};

