#pragma once

#include <QOpenGLWidget>
#include <qopenglfunctions_4_4_core.h>
#include <qopenglshaderprogram.h>
#include "ui_Render.h"
//#include "Cube.h"

class Cube;

class Render : public QOpenGLWidget, public QOpenGLFunctions_4_4_Core
{
	Q_OBJECT

public:
	Render(QWidget *parent = Q_NULLPTR);
	~Render();
	

protected : 
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int w, int h) override;

private:
	Ui::Render ui;
	QOpenGLShaderProgram shaderProgram;
	Cube* testCube;
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
};

