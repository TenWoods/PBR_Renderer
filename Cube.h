#pragma once
#include "RenderObject.h"
#include <qopenglfunctions_3_0.h>
#include <string>

class Cube : public RenderObject
{
private :
	float* cubeData;
	unsigned int VAO;
	unsigned int VBO;
	//unsigned int EBO;
	std::vector<Texture> textures;
public : 
	Cube();
	Cube(QVector3D position, QVector3D scale, QVector3D rotation, Render* window);
	void Draw(QOpenGLShaderProgram* shader) override;
	void AddTexture(std::string path);
};