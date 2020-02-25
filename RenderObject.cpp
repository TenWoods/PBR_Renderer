#include "RenderObject.h"

RenderObject::RenderObject() : m_position(0.0, 0.0, 0.0), m_scale(1.0, 1.0, 1.0), m_rotation(0.0, 0.0, 0.0), childObject(NULL), fatherObject(NULL), m_window(NULL)
{

}

RenderObject::RenderObject(QVector3D position, QVector3D scale, QVector3D rotation, Render* window) : m_position(position), m_scale(scale), m_rotation(rotation),
childObject(NULL), fatherObject(NULL), m_window(window)
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