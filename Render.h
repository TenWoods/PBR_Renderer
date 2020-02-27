#pragma once

#include <QOpenGLWidget>
#include <qopenglfunctions_4_4_core.h>
#include <qopenglshaderprogram.h>
#include "ui_Render.h"
#include "Camera.h"
#include <qkeyevent.h>
#include <qwindowdefs.h>
#include <QTime>

class Cube;

class Render : public QOpenGLWidget, public QOpenGLFunctions_4_4_Core
{
	Q_OBJECT

public:
	Render(QWidget *parent = Q_NULLPTR);
	~Render();
	Camera camera;

protected : 
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w, int h) override;
	void keyPressEvent(QKeyEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void focusInEvent(QFocusEvent* event) override;
	void focusOutEvent(QFocusEvent* event) override;

private:
	Ui::Render ui;
	QOpenGLShaderProgram shaderProgram;
	Cube* testCube;
	float lastFrame;
	float deltaTime;
	QTime time;
	float lastX;
	float lastY;
	bool isFirstMouse;
	bool isRightMousePress;
};

