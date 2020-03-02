#pragma once
#include <qvector3d.h>
#include <qopenglshaderprogram.h>
#include <vector>
#include <string>

class Render;

enum TEXTURE_TYPE
{
	NORMAL,
	DIFFUSE,
	HEIGHT,
	SPECULAR
};

struct Texture {
	unsigned int id;
	TEXTURE_TYPE type;
	std::string path;
};

class RenderObject
{
private : 
	RenderObject* childObject;
	RenderObject* fatherObject;
	bool hasNormalmap;
protected :
	Render* m_window;
	QVector3D m_position;
	QVector3D m_scale;
	QVector3D m_rotation;
public : 
	RenderObject();
	RenderObject(QVector3D position, QVector3D scale, QVector3D rotation, Render* window);
	void AddChild(RenderObject* child);
	void AddFather(RenderObject* father);
	bool get_hasNormalmap();
	void set_hasNornalmap(bool value);
	virtual void AddTexture(std::string path, TEXTURE_TYPE type) = 0;
	virtual void Draw(QOpenGLShaderProgram* shader) = 0;
};

struct Vertex {
	// position
	QVector3D position;
	// normal
	QVector3D normal;
	// texCoords
	QVector2D texcoord;
	// tangent
	QVector3D tangent;
	// bitangent
	QVector3D bitangent;
};
