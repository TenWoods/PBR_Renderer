#pragma once
#include "RenderObject.h"
class Sphere : public RenderObject
{
private :
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	std::vector<Texture> textures;
	int indexCount;
public :
	Sphere();
	Sphere(QVector3D position, QVector3D scale, QVector3D rotation, Render* window);
	void Draw(QOpenGLShaderProgram* shader);
	void AddTexture(std::string path, TEXTURE_TYPE type) override;
};

