#pragma once
#include "RenderObject.h"
#include <qopenglfunctions_3_0.h>

class Cube : public RenderObject
{
private :
	float* cubeData;
	unsigned int VAO;
	unsigned int VBO;
	//unsigned int EBO;
	std::vector<Texture> textures;
	//TODO:º”‘ÿÃ˘Õº
public : 
	Cube();
	Cube(QVector3D position, QVector3D scale, QVector3D rotation, Render* window);
	void Draw(QOpenGLShaderProgram* shader) override;
};

//const unsigned int indices[] = {  // note that we start from 0!
//		0, 1, 3,  // first Triangle
//		1, 2, 3   // second Triangle
//};
//const float vertex[] = {
//	// positions          // colors           
//	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
//		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
//		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
//		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f
//};

