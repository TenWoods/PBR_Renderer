#include "Camera.h"

Camera::Camera()
{
	position = QVector3D(0.0f, 0.0f, 0.0f);
	front = QVector3D(0.0f, 0.0f, -1.0f);
	up = QVector3D(0.0f, 1.0f, 0.0f);
	right = QVector3D(1.0f, 0.0f, 0.0f);
	moveSpeed = 1.0f;
	rotateSpeed = 1.0f;
	m_zoom = qDegreesToRadians(45.0f);
}

Camera::Camera(QVector3D pos, QVector3D lookAtPoint, float moves, float rotates, float zoom) : position(pos), moveSpeed(moves), rotateSpeed(rotates), m_zoom(zoom), front(lookAtPoint - pos), 
yaw(270.0f), pitch(0.0f)
{
	QVector3D worldUp(0.0f, 1.0f, 0.0f);
	front.normalize();
	right = QVector3D::crossProduct(worldUp, front);
	up = QVector3D::crossProduct(front, right);
	right.normalize();
	up.normalize();
}

QMatrix4x4 Camera::ViewMatrix()
{
	QMatrix4x4 view;
	view.lookAt(position, position + front, up);
	return view;
}

float Camera::get_zoom()
{
	return m_zoom;
}

QVector3D Camera::get_position()
{
	return position;
}

void Camera::Move(Direction dir, float deltaTime)
{
	switch (dir)
	{
	case Direction::Forward:
		position += front * moveSpeed * deltaTime;
		break;
	case Direction::Backward:
		position -= front * moveSpeed * deltaTime;
		break;
	case Direction::Right:
		position -= right * moveSpeed * deltaTime;
		break;
	case Direction::Left:
		position += right * moveSpeed * deltaTime;
		break;
	case Direction::Up:
		position += up * moveSpeed * deltaTime;
		break;
	case Direction::Down:
		position -= up * moveSpeed * deltaTime;
		break;
	default:
		break;
	}
}

void Camera::Rotate(float deltaX, float deltaY)
{
	yaw += deltaX * rotateSpeed;
	pitch += deltaY * rotateSpeed;
	if (pitch > 89.0f)
	{
		qDebug() << "?";
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}
	UpdateVector();
}

void Camera::UpdateVector()
{
	//qDebug() << yaw << ' ' << pitch;
	float radian_pitch = qDegreesToRadians(pitch);
	float radian_yaw = qDegreesToRadians(yaw);
	front.setX(cos(radian_pitch) * cos(radian_yaw));
	front.setY(sin(radian_pitch));
	front.setZ(cos(radian_pitch) * sin(radian_yaw));
	front.normalize();
	right = QVector3D::crossProduct(QVector3D(0.0f, 1.0f, 0.0f), front);
	up = QVector3D::crossProduct(front, right);
}