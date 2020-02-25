#pragma once
#include <qvector3d.h>
#include <qopenglshaderprogram.h>
#include <vector>
#include <string>
#include "Render.h"

class RenderObject
{
private : 
	QVector3D m_position;
	QVector3D m_scale;
	QVector3D m_rotation;
	RenderObject* childObject;
	RenderObject* fatherObject;
protected :
	Render *m_window;
public : 
	RenderObject();
	RenderObject(QVector3D position, QVector3D scale, QVector3D rotation, Render* window);
	void AddChild(RenderObject* child);
	void AddFather(RenderObject* father);
	virtual void Draw(QOpenGLShaderProgram* shader) = 0;
};

struct Texture {
	unsigned int id;
	std::string type;
	std::string path;
};

struct Vertex {
	// position
	QVector3D Position;
	// normal
	QVector3D Normal;
	// texCoords
	QVector2D TexCoords;
	// tangent
	QVector3D Tangent;
	// bitangent
	QVector3D Bitangent;
};
