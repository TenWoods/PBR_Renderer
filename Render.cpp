#include "Render.h"
#include "Cube.h"

Render::Render(QWidget *parent)
	: QOpenGLWidget(parent)
{
	ui.setupUi(this);
}

Render::~Render()
{

}

void Render::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
	bool success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex/testVertex.vert");
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << shaderProgram.log();
		return;
	}
	success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment/testFragment.frag");
	if (!success)
	{
		qDebug() << "load frag shader failed!" << shaderProgram.log();
		return;
	}
	success = shaderProgram.link();
	if (!success)
	{
		qDebug() << "shader program link failed" << shaderProgram.log();
		return;
	}
	testCube = new Cube(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), this);
}

void Render::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
	testCube->Draw(&shaderProgram);
}

void Render::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}