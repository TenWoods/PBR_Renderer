#include "RenderObject.h"
#include "Render.h"

RenderObject::RenderObject() : m_position(0.0, 0.0, 0.0), m_scale(1.0, 1.0, 1.0), m_rotation(0.0, 0.0, 0.0), childObject(NULL), fatherObject(NULL), m_window(NULL), hasNormalmap(false), color(0.0f, 0.0f, 0.5f), metallic(0.5f), roughness(0.5f), ao(1.0f)
{

}

RenderObject::RenderObject(QVector3D position, QVector3D scale, QVector3D rotation, Render* window) : m_position(position), m_scale(scale), m_rotation(rotation),
childObject(NULL), fatherObject(NULL), m_window(window), hasNormalmap(false), color(0.0f, 0.0f, 0.5f), metallic(0.5f), roughness(0.5f), ao(1.0f)
{

}

void RenderObject::AddChild(RenderObject* child)
{
	childObject = child;
}

void RenderObject::AddFather(RenderObject* father)
{
	fatherObject = father;
}

bool RenderObject::get_hasNormalmap()
{
	return hasNormalmap;
}

void RenderObject::set_hasNornalmap(bool value)
{
	hasNormalmap = value;
}

void RenderObject::set_position(QVector3D value)
{
	m_position = value;
}

QVector3D RenderObject::get_position()
{
	return m_position;
}

void RenderObject::set_scale(QVector3D value)
{
	m_scale = value;
}

QVector3D RenderObject::get_scale()
{
	return m_scale;
}
void RenderObject::set_rotation(QVector3D value)
{
	m_rotation = value;
}

QVector3D RenderObject::get_rotation()
{
	return m_rotation;
}

void RenderObject::set_color(QVector3D value)
{
	color = value;
}

QVector3D RenderObject::get_color()
{
	return color;
}

void RenderObject::set_metallic(float value)
{
	metallic = value;
}

float RenderObject::get_metallic()
{
	return metallic;
}

void RenderObject::set_roughness(float value)
{
	roughness = value;
}

float RenderObject::get_roughness()
{
	return roughness;
}

void RenderObject::set_ao(float value)
{
	ao = value;
}

float RenderObject::get_ao()
{
	return ao;
}