#pragma once
#include <qvector3d.h>
#include <qopenglshaderprogram.h>
#include <vector>
#include <string>
#include <glm\glm.hpp>

class Render;

enum TEXTURE_TYPE
{
	NORMAL,
	DIFFUSE,
	HEIGHT,
	SPECULAR,
	METALLIC,
	ROUGHNESS,
	AO
};

struct Texture 
{
	unsigned int id;
	TEXTURE_TYPE type;
	std::string path;
};

struct Vertex
{
	//位置
	glm::vec3 position;
	//法线
	glm::vec3 normal;
	//切线
	glm::vec3 tangent;
	//纹理坐标
	glm::vec2 texcoord;
	//副切线
	glm::vec3 bitangent;
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
	std::vector<Texture> textures;
	QVector3D color;
	float metallic;
	float roughness;
	float ao;
public : 
	RenderObject();
	RenderObject(QVector3D position, QVector3D scale, QVector3D rotation, Render* window);
	void AddChild(RenderObject* child);
	void AddFather(RenderObject* father);
	bool get_hasNormalmap();
	void set_hasNornalmap(bool value);
	void set_position(QVector3D value);
	QVector3D get_position();
	void set_scale(QVector3D value);
	QVector3D get_scale();
	void set_rotation(QVector3D value);
	QVector3D get_rotation();
	void set_color(QVector3D value);
	QVector3D get_color();
	void set_metallic(float value);
	float get_metallic();
	void set_roughness(float value);
	float get_roughness();
	void set_ao(float value);
	float get_ao();
	virtual void AddTexture(std::string path, TEXTURE_TYPE type) = 0;
	virtual void Draw(QOpenGLShaderProgram* shader) = 0;
};
