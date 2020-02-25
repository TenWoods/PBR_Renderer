#pragma once
#include <qvector3d.h>
#include <qmatrix4x4.h>

class Camera
{
private :
	QVector3D position;
	QVector3D front;
	QVector3D up;
	QVector3D right;
	float moveSpeed;
	float rotateSpeed;
public :
	Camera();
	Camera(QVector3D pos, QVector3D front, QVector3D worldUp, float moves, float rotates);
	QMatrix4x4 ViewMatrix();
	void Move();
	void Rotate();

};

