#include "Camera.h"

Camera::Camera()
{
	position = QVector3D(0.0f, 0.0f, 0.0f);
	front = QVector3D(0.0f, 0.0f, 1.0f);
	up = QVector3D(0.0f, 1.0f, 0.0f);
	right = QVector3D(1.0f, 0.0f, 0.0f);
	moveSpeed = 1.0f;
	rotateSpeed = 1.0f;
}

Camera::Camera(QVector3D pos, QVector3D front, QVector3D worldUp, float moves, float rotates) : position(pos), front(front), moveSpeed(moves), rotateSpeed(rotates)
{
	right = QVector3D::crossProduct(worldUp, front);
	up = QVector3D::crossProduct(right, front);
}