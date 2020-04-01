#include "Render.h"
#include "RenderObject.h"

Render::Render(QWidget* parent)
	: QOpenGLWidget(parent), camera(QVector3D(0.0f, 0.0f, 2.0f), QVector3D(0.0f, 0.0f, 0.0f), 5.0f, 0.1f, 45.0f), 
	lastFrame(0.0f), deltaTime(0.0f), time(), 
	isFirstMouse(true), isRightMousePress(false),
	lastX(0.0f), lastY(0.0f), focusObject(NULL), PBRMaterialON(false), textureON(false), isLoadModel(false), loadModelPath(), sceneObjects()
{
	ui.setupUi(this);
}

Render::~Render()
{

}

void Render::initializeGL()
{
	//��ʼ��OpenGL״̬
	initializeOpenGLFunctions();
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	//��ʼ��������ɫ��
	//��ͳ����ͼ
	bool success = traditonal_notex_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex/baseVertex.vert");
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << traditonal_notex_shader.log();
		return;
	}
	success = traditonal_notex_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment/traditionalFragment_notexture.frag");
	if (!success)
	{
		qDebug() << "load frag shader failed!" << traditonal_notex_shader.log();
		return;
	}
	success = traditonal_notex_shader.link();
	if (!success)
	{
		qDebug() << "shader program link failed" << traditonal_notex_shader.log();
		return;
	}

	//��ͳ����ͼ
	success = traditonal_tex_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex/baseVertex.vert");
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << traditonal_tex_shader.log();
		return;
	}
	success = traditonal_tex_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment/traditionalFragment_withTexture.frag");
	if (!success)
	{
		qDebug() << "load frag shader failed!" << traditonal_tex_shader.log();
		return;
	}
	success = traditonal_tex_shader.link();
	if (!success)
	{
		qDebug() << "shader program link failed" << traditonal_tex_shader.log();
		return;
	}

	//PBR����ͼ
	success = pbr_notex_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex/baseVertex.vert");
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << pbr_notex_shader.log();
		return;
	}
	success = pbr_notex_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment/basePBRFragment.frag");
	if (!success)
	{
		qDebug() << "load frag shader failed!" << pbr_notex_shader.log();
		return;
	}
	success = pbr_notex_shader.link();
	if (!success)
	{
		qDebug() << "shader program link failed" << pbr_notex_shader.log();
		return;
	}

	//PBR����ͼ
	success = pbr_tex_shader.addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex/baseVertex.vert");
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << pbr_tex_shader.log();
		return;
	}
	success = pbr_tex_shader.addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment/PBRFragment_withtextures.frag");
	if (!success)
	{
		qDebug() << "load frag shader failed!" << pbr_tex_shader.log();
		return;
	}
	success = pbr_tex_shader.link();
	if (!success)
	{
		qDebug() << "shader program link failed" << pbr_tex_shader.log();
		return;
	}

	//������ʱ
	time.start();
	//��������
	//sceneObjects.push_back(new Model("C:/WorkPlace/PBR_Renderer/PBR_Renderer/model/test.obj", this));
	//����ƽ�й�
	/*directionLight = DirectionLight(QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-0.2f, -1.0f, -0.3f));*/
	//���Դ
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-10.0f, 10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(10.0f, 10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-10.0f, -10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(10.0f, -10.0f, 10.0f), 0.09f, 0.032f));
	//�۹�
	/*spotLights.push_back(SpotLight(QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(0.0f, 0.0f, 2.0f), 0.09f, 0.032f, QVector3D(0.0f, 0.0f, -2.0f), cos(qDegreesToRadians(12.5f)), cos(qDegreesToRadians(15.0f))));*/
}

void Render::paintGL()
{
	textureON = true;	//debug
	if (isLoadModel)
	{
		sceneObjects.push_back(new Model(loadModelPath, this));
		isLoadModel = false;
	}
	update();
	//�ж�ʹ��������ɫ��
	if (textureON)
	{
		if (PBRMaterialON)
		{
			shaderProgram = &pbr_tex_shader;
		}
		else
		{
			shaderProgram = &traditonal_tex_shader;
		}
	}
	else
	{
		if (PBRMaterialON)
		{
			shaderProgram = &pbr_notex_shader;
		}
		else
		{
			shaderProgram = &traditonal_notex_shader;
		}
	}
	//shaderProgram = &traditonal_tex_shader;
	float currentTime = (float)time.elapsed() / 1000;
	deltaTime = currentTime - lastFrame;
	lastFrame = currentTime;
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//�ѹ�����Ϣ�������Ϣ����shader
	shaderProgram->bind();
	shaderProgram->setUniformValue("cameraPos", camera.get_position());
	////ƽ�й���Ϣ
	//shaderProgram->setUniformValue("dirLight.direction", directionLight.get_direction());
	//shaderProgram->setUniformValue("dirLight.ambient", directionLight.get_ambient());
	//if (PBRMaterialON)
	//{
	//	shaderProgram->setUniformValue("dirLight.lightColor", directionLight.get_lightColor() * 300.0f);
	//}
	//else
	//{
	//	shaderProgram->setUniformValue("dirLight.lightColor", directionLight.get_lightColor());
	//}
	//���Դ��Ϣ
	shaderProgram->setUniformValue("plNum", (int)pointLights.size());
	for (int i = 0; i < pointLights.size(); i++)
	{
		shaderProgram->setUniformValue(("pointLights[" + std::to_string(i) + "].position").c_str(), pointLights[i].get_position());
		shaderProgram->setUniformValue(("pointLights[" + std::to_string(i) + "].constant").c_str(), pointLights[i].get_constant());
		shaderProgram->setUniformValue(("pointLights[" + std::to_string(i) + "].linear").c_str(), pointLights[i].get_linear());
		shaderProgram->setUniformValue(("pointLights[" + std::to_string(i) + "].quadratic").c_str(), pointLights[i].get_quadratic());
		shaderProgram->setUniformValue(("pointLights[" + std::to_string(i) + "].ambient").c_str(), pointLights[i].get_ambient());
		if (PBRMaterialON)
		{
			shaderProgram->setUniformValue(("pointLights[" + std::to_string(i) + std::string("].lightColor")).c_str(),
				pointLights[i].get_lightColor() * 60.0f);
		}
		else
		{
			shaderProgram->setUniformValue(("pointLights[" + std::to_string(i) + std::string("].lightColor")).c_str(),
				pointLights[i].get_lightColor());
		}
	}
	//�۹���Ϣ
	shaderProgram->setUniformValue("slNum", (int)spotLights.size());
	for (int i = 0; i < spotLights.size(); i++)
	{
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].position").c_str(), spotLights[i].get_position());
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].direction").c_str(),
			spotLights[i].get_direction());
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].constant").c_str(), spotLights[i].get_constant());
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].linear").c_str(), spotLights[i].get_linear());
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].quadratic").c_str(), spotLights[i].get_quadratic());
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].ambient").c_str(), spotLights[i].get_ambient());
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].cutOff").c_str(), spotLights[i].get_cutoff());
		shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].cutoffout").c_str(), spotLights[i].get_cutoffout());
		if (PBRMaterialON)
		{
			shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].lightColor").c_str(), spotLights[i].get_lightColor() * 300.0f);
		}
		else
		{
			shaderProgram->setUniformValue(("spotLights[" + std::to_string(i) + "].lightColor").c_str(), spotLights[i].get_lightColor());
		}
	}
	//���Ƴ���
	for (int i = 0; i < sceneObjects.size(); i++)
	{
		if (sceneObjects[i] == NULL)
		{
			continue;
		}
		sceneObjects[i]->Draw(shaderProgram);
	}
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
	float deltaY = event->pos().y() - lastY;
	lastY = event->y();
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
	if (isRightMousePress)
		return;
	lastX = event->x();
	lastY = event->y();
	isRightMousePress = true;
}

//���õ���¼�
void Render::mouseReleaseEvent(QMouseEvent* event)
{
	isRightMousePress = false;
}

void Render::set_focusObject(int i)
{
	focusObject = sceneObjects[i];
}

RenderObject* Render::get_focusObject()
{
	return focusObject;
}

bool Render::get_textureON()
{
	return textureON;
}

bool Render::get_PBRMaterialON()
{
	return PBRMaterialON;
}

//�ۺ���
int Render::AddCube()
{
	sceneObjects.push_back(new Cube(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), this));
	//qDebug() << sceneObjects.size();
	return sceneObjects.size() - 1;
}

int Render::AddSphere()
{
	sceneObjects.push_back(new Sphere(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), this));
	//qDebug() << sceneObjects.size();
	return sceneObjects.size() - 1;
}

int Render::AddModel(std::string path)
{
	isLoadModel = true;
	loadModelPath = path;
	qDebug() << sceneObjects.size();
	return sceneObjects.size();   //TODO: ���û��ƺ���ʵʱ����index?
}

//�ı����ԵĲۺ���
//λ�øı�
void Render::ChangePositionX(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D position = focusObject->get_position();
	position.setX(text.toFloat());
	focusObject->set_position(position);
}

void Render::ChangePositionY(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D position = focusObject->get_position();
	position.setY(text.toFloat());
	focusObject->set_position(position);
}

void Render::ChangePositionZ(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D position = focusObject->get_position();
	position.setZ(text.toFloat());
	focusObject->set_position(position);
}

//��С�ı�
void Render::ChangeScaleX(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D scale = focusObject->get_scale();
	scale.setX(text.toFloat());
	focusObject->set_scale(scale);
}

void Render::ChangeScaleY(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D scale = focusObject->get_scale();
	scale.setY(text.toFloat());
	focusObject->set_scale(scale);
}

void Render::ChangeScaleZ(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D scale = focusObject->get_scale();
	scale.setZ(text.toFloat());
	focusObject->set_scale(scale);
}

//��ת�ı�
void Render::ChangeRotationX(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D rotation = focusObject->get_rotation();
	rotation.setX(text.toFloat());
	focusObject->set_rotation(rotation);
}

void Render::ChangeRotationY(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D rotation = focusObject->get_rotation();
	rotation.setY(text.toFloat());
	focusObject->set_rotation(rotation);
}

void Render::ChangeRotationZ(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D rotation = focusObject->get_rotation();
	rotation.setZ(text.toFloat());
	focusObject->set_rotation(rotation);
}

//��ɫ�ı�
void Render::ChangeColorR(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D color = focusObject->get_color();
	color.setX(text.toFloat());
	focusObject->set_color(color);
}

void Render::ChangeColorG(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D color = focusObject->get_color();
	color.setY(text.toFloat());
	focusObject->set_color(color);
}

void Render::ChangeColorB(const QString& text)
{
	if (focusObject == NULL)
		return;
	QVector3D color = focusObject->get_color();
	color.setZ(text.toFloat());
	focusObject->set_color(color);
}

//�����ȸı�
void Render::ChangeMetallic(const QString& text)
{
	if (focusObject == NULL)
		return;
	focusObject->set_metallic(text.toFloat());
}

//�ֲڶȸı�
void Render::ChangeRoughness(const QString& text)
{
	if (focusObject == NULL)
		return;
	focusObject->set_roughness(text.toFloat());
}

//ao�ı�
void Render::ChangeAO(const QString& text)
{
	if (focusObject == NULL)
		return;
	focusObject->set_ao(text.toFloat());
}

//���ܿ���
void Render::SettextureON(bool value)
{
	textureON = value;
}

void Render::SetPBRMaterialON(bool value)
{
	PBRMaterialON = value;
}