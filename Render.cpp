#include "Render.h"
#include "Cube.h"

Render::Render(QWidget* parent)
	: QOpenGLWidget(parent), camera(QVector3D(0.0f, 0.0f, 2.0f), QVector3D(0.0f, 0.0f, 0.0f), 5.0f, 0.1f, 45.0f), 
	lastFrame(0.0f), deltaTime(0.0f), time(), 
	isFirstMouse(true), isRightMousePress(false),
	lastX(0.0f), lastY(0.0f)
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
	bool success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex/traditionalVertex.vert");
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << shaderProgram.log();
		return;
	}
	success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment/traditionalFragment.frag");
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
	time.start();
}

void Render::paintGL()
{
	//qDebug() << camera.pitch << ' ' << camera.yaw;
	float currentTime = (float)time.elapsed() / 1000;
	deltaTime = currentTime - lastFrame;
	lastFrame = currentTime;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	testCube->Draw(&shaderProgram);
	update();
}

void Render::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}

//���������
void Render::keyPressEvent(QKeyEvent* event)
{
	switch (event->key())
	{
	case Qt::Key_W :
		camera.Move(Direction::Forward, deltaTime);
		break;
	case Qt::Key_S:
		camera.Move(Direction::Backward, deltaTime);
		break;
	case Qt::Key_A:
		camera.Move(Direction::Left, deltaTime);
		break;
	case Qt::Key_D:
		camera.Move(Direction::Right, deltaTime);
		break;
	case Qt::Key_Q:
		camera.Move(Direction::Up, deltaTime);
		break;
	case Qt::Key_E:
		camera.Move(Direction::Down, deltaTime);
		break;
	default:
		break;
	}
	//qDebug() << camera.position;
}

//��������ƶ��¼�
void Render::mouseMoveEvent(QMouseEvent* event)
{
	if (isFirstMouse)
	{
		lastX = (float)width() / 2;
		lastY = (float)height() / 2;
		isFirstMouse = false;
		return;
	}
	float deltaX = event->pos().x() - lastX;
	lastX = event->x();
	//qDebug() << deltaX;
	float deltaY = event->pos().y() - lastY;
	lastY = event->y();
	//qDebug() << deltaY;
	camera.Rotate(deltaX, deltaY);
}

//ѡ�д���ʱ����
void Render::focusInEvent(QFocusEvent* event)
{
	//������
	QPoint position = mapToGlobal(pos());
	QCursor::setPos(width() / 2 + position.x(), height() / 2 + position.y());
}

//�뿪����ʱ����
void Render::focusOutEvent(QFocusEvent* event)
{
	isFirstMouse = true;
}

//�����������ק������������ϴ�λ��
void Render::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
	{
		if (isRightMousePress)
			return;
		lastX = event->x();
		lastY = event->y();
		isRightMousePress = true;
	}
}

//���õ���¼�
void Render::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::RightButton)
	{
		isRightMousePress = false;
	}
}