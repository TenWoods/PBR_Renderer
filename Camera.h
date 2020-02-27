#pragma once
#include <qvector3d.h>
#include <qmatrix4x4.h>
#include <qmath.h>

enum class Direction
{
	Forward,
	Backward,
	Right,
	Left,
	Up,
	Down
};

class Camera
{
private :
	QVector3D position;
	QVector3D front;
	QVector3D up;
	QVector3D right;
	float moveSpeed;
	float rotateSpeed;
	float m_zoom;
	float pitch;
	float yaw;
	void UpdateVector();

public :
	Camera();
	Camera(QVector3D pos, QVector3D lookAtPoint, float moves, float rotates, float zoom);
	QMatrix4x4 ViewMatrix();
	void Move(Direction dir, float deltaTime);
	void Rotate(float deltaX, float deltaY);
	float Zoom();
};

