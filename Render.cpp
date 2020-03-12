#include "Render.h"
#include "RenderObject.h"

Render::Render(QWidget* parent)
	: QOpenGLWidget(parent), camera(QVector3D(0.0f, 0.0f, -2.0f), QVector3D(0.0f, 0.0f, 0.0f), 5.0f, 0.1f, 45.0f), 
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
	//初始化OpenGL状态和着色器
	initializeOpenGLFunctions();
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	bool success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex/traditionalVertex.vert");
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << shaderProgram.log();
		return;
	}
	success = shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment/PBRFragment.frag");
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
	//开启计时
	time.start();
	//初始化场景物体
	sceneObjects.push_back(new Sphere(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), this));
	sceneObjects[0]->set_hasNornalmap(false);
	sceneObjects[0]->AddTexture("brickwall.jpg", TEXTURE_TYPE::DIFFUSE);
	sceneObjects[0]->AddTexture("brickwall_normal.jpg", TEXTURE_TYPE::NORMAL);
	//基础平行光
	directionLight = DirectionLight(QVector3D(150.0f, 150.0f, 150.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-0.2f, -1.0f, -0.3f));
	//点光源
	pointLights.push_back(PointLight(QVector3D(300.0f, 300.0f, 300.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-10.0f, 10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(300.0f, 300.0f, 300.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(10.0f, 10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(300.0f, 300.0f, 300.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-10.0f, -10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(300.0f, 300.0f, 300.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(10.0f, -10.0f, 10.0f), 0.09f, 0.032f));
	//聚光
	spotLights.push_back(SpotLight(QVector3D(0.0f, 0.0f, 300.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(0.0f, 0.0f, 2.0f), 0.09f, 0.032f, QVector3D(0.0f, 0.0f, -2.0f), cos(qDegreesToRadians(12.5f)), cos(qDegreesToRadians(15.0f))));
}

void Render::paintGL()
{
	float currentTime = (float)time.elapsed() / 1000;
	deltaTime = currentTime - lastFrame;
	lastFrame = currentTime;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//把光照信息和相机信息传给shader
	shaderProgram.bind();
	shaderProgram.setUniformValue("cameraPos", camera.get_position());
	//平行光信息
	shaderProgram.setUniformValue("dirLight.direction", directionLight.get_direction());
	shaderProgram.setUniformValue("dirLight.lightColor", directionLight.get_lightColor());
	shaderProgram.setUniformValue("dirLight.ambient", directionLight.get_ambient());
	//点光源信息
	shaderProgram.setUniformValue("plNum", (int)pointLights.size());
	for (int i = 0; i < pointLights.size(); i++)
	{
		shaderProgram.setUniformValue(("pointLights[" + std::to_string(i) + "].position").c_str(), pointLights[i].get_position());
		shaderProgram.setUniformValue(("pointLights[" + std::to_string(i) + "].constant").c_str(), pointLights[i].get_constant());
		shaderProgram.setUniformValue(("pointLights[" + std::to_string(i) + "].linear").c_str(), pointLights[i].get_linear());
		shaderProgram.setUniformValue(("pointLights[" + std::to_string(i) + "].quadratic").c_str(), pointLights[i].get_quadratic());
		shaderProgram.setUniformValue(("pointLights[" + std::to_string(i) + "].ambient").c_str(), pointLights[i].get_ambient());
		shaderProgram.setUniformValue(("pointLights[" + std::to_string(i) + std::string("].lightColor")).c_str(), 
			pointLights[i].get_lightColor());
	}
	//聚光信息
	shaderProgram.setUniformValue("slNum", (int)spotLights.size());
	for (int i = 0; i < spotLights.size(); i++)
	{
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].position").c_str(), spotLights[i].get_position());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].direction").c_str(), 
			spotLights[i].get_direction());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].constant").c_str(), spotLights[i].get_constant());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].linear").c_str(), spotLights[i].get_linear());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].quadratic").c_str(), spotLights[i].get_quadratic());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].ambient").c_str(), spotLights[i].get_ambient());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].lightColor").c_str(), spotLights[i].get_lightColor());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].cutOff").c_str(), spotLights[i].get_cutoff());
		shaderProgram.setUniformValue(("spotLights[" + std::to_string(i) + "].cutoffout").c_str(), spotLights[i].get_cutoffout());
	}
	shaderProgram.setUniformValue("albedo", QVector3D(0.5f, 0.0f, 0.0f));
	shaderProgram.setUniformValue("ao", 1.0f);
	shaderProgram.setUniformValue("metallic", 0.5f);
	shaderProgram.setUniformValue("roughness", 0.5f);
	//绘制场景
	for each (auto obj in sceneObjects)
	{
		obj->Draw(&shaderProgram);
	}
	update();
}

void Render::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
}

//处理按键点击
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

//处理鼠标移动事件
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

//选中窗口时处理
void Render::focusInEvent(QFocusEvent* event)
{
	//鼠标居中
	QPoint position = mapToGlobal(pos());
	QCursor::setPos(width() / 2 + position.x(), height() / 2 + position.y());
}

//离开窗口时处理
void Render::focusOutEvent(QFocusEvent* event)
{
	isFirstMouse = true;
}

//鼠标左键点击拖拽，点击是重置上次位置
void Render::mousePressEvent(QMouseEvent* event)
{
	if (isRightMousePress)
		return;
	lastX = event->x();
	lastY = event->y();
	isRightMousePress = true;
}

//重置点击事件
void Render::mouseReleaseEvent(QMouseEvent* event)
{
	isRightMousePress = false;
}