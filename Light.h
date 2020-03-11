#pragma once
#include <qvector3d.h>

class Light
{
private :
	QVector3D m_lightColor;
	QVector3D m_ambient;

public : 
	Light() : m_lightColor(0.0f, 0.0f, 0.0f), m_ambient(0.0f, 0.0f, 0.0f)
	{

	}

	Light(QVector3D lightColor, QVector3D ambient) : m_lightColor(lightColor), m_ambient(ambient)
	{

	}

	void set_diffuse(QVector3D value)
	{
		m_lightColor = value;
	}

	void set_ambient(QVector3D value)
	{
		m_ambient = value;
	}

	QVector3D get_lightColor()
	{
		return m_lightColor;
	}

	QVector3D get_ambient()
	{
		return m_ambient;
	}
};

//定向光源
class DirectionLight : public Light
{
private : 
	QVector3D m_direction;

public :
	DirectionLight() : Light(), m_direction(0.0f, -1.0f, 0.0f)
	{

	}

	DirectionLight(QVector3D diffuse, QVector3D ambient, QVector3D direction) : Light(diffuse, ambient), m_direction(direction)
	{

	}

	void set_direction(QVector3D direction)
	{
		m_direction = direction;
	}

	QVector3D get_direction()
	{
		return m_direction;
	}
};

//点光源
class PointLight : public Light
{
private :
	QVector3D m_position;
	float m_constant;
	float m_linear;
	float m_quadratic;
public :
	PointLight() : Light(), m_position(0.0f, 0.0f, 0.0f), m_constant(1.0f), m_linear(0.7f), m_quadratic(1.8f)
	{

	}

	PointLight(QVector3D lightColor, QVector3D ambient, QVector3D position, float linear, float quadratic) : Light(lightColor, ambient), m_position(position), m_constant(1.0f), m_linear(linear), m_quadratic(quadratic)
	{

	}

	void set_position(QVector3D newPosition)
	{
		m_position = newPosition;
	}

	void set_linear(float newLinear)
	{
		m_linear = newLinear;
	}

	void set_quadratic(float newQuadratic)
	{
		m_quadratic = newQuadratic;
	}

	QVector3D get_position()
	{
		return m_position;
	}

	float get_constant()
	{
		return m_constant;
	}

	float get_linear()
	{
		return m_linear;
	}

	float get_quadratic()
	{
		return m_quadratic;
	}
};

//聚光
class SpotLight : public PointLight
{
private :
	QVector3D m_direction;
	float m_cutoff;
	float m_cutoffout;
public :
	SpotLight() : PointLight(), m_direction(0.0f, 1.0f, 0.0f), m_cutoff(0.0f), m_cutoffout(0.0f)
	{

	}

	SpotLight(QVector3D diffuse, QVector3D ambient, QVector3D position, float linear, float quadratic, QVector3D direction, float cutoff, float cutoffout) : PointLight(diffuse, ambient, position, linear, quadratic), m_direction(direction), m_cutoff(cutoff), m_cutoffout(cutoffout)
	{

	}

	void set_direction(QVector3D newDirection)
	{
		m_direction = newDirection;
	}

	void set_cutoff(float newCutoff)
	{
		m_cutoff = newCutoff;
	}

	void set_cutoffout(float newCutoffout)
	{
		m_cutoffout = newCutoffout;
	}

	QVector3D get_direction()
	{
		return m_direction;
	}

	float get_cutoff()
	{
		return m_cutoff;
	}

	float get_cutoffout()
	{
		return	 m_cutoffout;
	}
};