#include "Render.h"
#include "RenderObject.h"
#include "PBR_Renderer.h"
#include "stb_image.h"


Render::Render(QWidget* parent)
	: QOpenGLWidget(parent), camera(QVector3D(0.0f, 0.0f, 2.0f), QVector3D(0.0f, 0.0f, 0.0f), 5.0f, 0.1f, 45.0f),
	lastFrame(0.0f), deltaTime(0.0f), time(),
	isFirstMouse(true), isRightMousePress(false), textureON(false), isLoadModel(false), isEnvON(false), isFirstLoadEnv(true),
	lastX(0.0f), lastY(0.0f), target(NULL), loadModelPath(), sceneObjects(), cubeVAO(0), cubeVBO(0)
{
	ui.setupUi(this);
}

Render::~Render()
{

}

void Render::initializeGL()
{
	//初始化OpenGL状态
	initializeOpenGLFunctions();
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	//初始化所有着色器
	//传统无贴图
	InitShaderProgram("shaders/vertex/baseVertex.vert", "shaders/fragment/traditionalFragment_notexture.frag", traditonal_notex_shader);
	//传统有贴图
	InitShaderProgram("shaders/vertex/baseVertex.vert", "shaders/fragment/traditionalFragment_withTexture.frag", traditonal_tex_shader);
	//PBR无贴图
	InitShaderProgram("shaders/vertex/baseVertex.vert", "shaders/fragment/basePBRFragment.frag", pbr_notex_shader);
	//PBR有贴图
	InitShaderProgram("shaders/vertex/baseVertex.vert", "shaders/fragment/PBRFragment_withtextures.frag", pbr_tex_shader);
	//hdr贴图转立方贴图shader
	InitShaderProgram("shaders/vertex/cubemap.vert", "shaders/fragment/equirectangle_to_cubemap.frag", envTocube_shader);
	//漫反射辐照计算shader
	InitShaderProgram("shaders/vertex/cubemap.vert", "shaders/fragment/irradiance_convolution.frag", irradiance_shader);
	//漫反射辐照图PBR shader
	InitShaderProgram("shaders/vertex/baseVertex.vert", "shaders/fragment/irradiancePBR.frag", envPBR_notex_shader);
	//天空盒渲染shader
	InitShaderProgram("shaders/vertex/background.vert", "shaders/fragment/background.frag", background_shader);
	
	/*std::vector<std::string> faces
	{
		"skybox/right.jpg",
		"skybox/left.jpg",
		"skybox/top.jpg",
		"skybox/bottom.jpg",
		"skybox/front.jpg",
		"skybox/back.jpg"
	};
	glGenTextures(1, &envCubeMap);
	glBindTexture(GL_TEXTURE_CUBE_MAP, envCubeMap);
	int width, height, nrChannels;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else
		{
			qDebug() << "Cubemap texture failed to load at path: " << i;
		}
		stbi_image_free(data);
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);*/

	//使用环境贴图的pbr无贴图shader
	//InitShaderProgram("shaders/vertex/background.vert", "shaders/fragment/background.frag", envPBR_notex_shader);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//开启计时
	time.start();
	//测试物体
	//sceneObjects.push_back(new Model("C:/WorkPlace/PBR_Renderer/PBR_Renderer/model/test.obj", this));
	//基础平行光
	/*directionLight = DirectionLight(QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-0.2f, -1.0f, -0.3f));*/
	//点光源
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-10.0f, 10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(10.0f, 10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(-10.0f, -10.0f, 10.0f), 0.09f, 0.032f));
	pointLights.push_back(PointLight(QVector3D(5.0f, 5.0f, 5.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(10.0f, -10.0f, 10.0f), 0.09f, 0.032f));
	//聚光
	/*spotLights.push_back(SpotLight(QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.2f, 0.2f, 0.2f), QVector3D(0.0f, 0.0f, 2.0f), 0.09f, 0.032f, QVector3D(0.0f, 0.0f, -2.0f), cos(qDegreesToRadians(12.5f)), cos(qDegreesToRadians(15.0f))));*/
}

void Render::paintGL()
{
	isEnvON = true;
	//textureON = true;	//debug
	if (isLoadModel)
	{
		Model* model = new Model(loadModelPath, this);
		sceneObjects.push_back(model);
		int size = model->get_meshsize();
		for (int i = 0; i < size; i++)
		{
			sceneObjects.push_back(model->get_meshpointer(i));
		}
		emit SetMeshUI(model);
		isLoadModel = false;
	}
	update();
	//判断使用哪种着色器
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
		else if (isEnvON)
		{
			shaderProgram = &envPBR_notex_shader;
		}
		else
		{
			shaderProgram = &traditonal_notex_shader;
		}
	}
	float currentTime = (float)time.elapsed() / 1000;
	deltaTime = currentTime - lastFrame;
	lastFrame = currentTime;
	
	//开启环境贴图的前置渲染数据
	if (isEnvON)
	{
		if (isFirstLoadEnv)
		{
			glGenFramebuffers(1, &captureFBO);
			glGenRenderbuffers(1, &captureRBO);
			glBindFramebuffer(GL_FRAMEBUFFER, captureFBO);
			glBindRenderbuffer(GL_RENDERBUFFER, captureRBO);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, 512, 512);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, captureRBO);
			glGenTextures(1, &hdrTexture);
			glBindTexture(GL_TEXTURE_2D, hdrTexture);
			stbi_set_flip_vertically_on_load(true);
			int width, height, nrComponents;
			float* data = stbi_loadf("Alexs_Apt_2k.hdr", &width, &height, &nrComponents, 0);
			if (data)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, width, height, 0, GL_RGB, GL_FLOAT, data);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				stbi_image_free(data);
			}
			else
			{
				qDebug() << "faild to load HDR image";
			}
			glGenTextures(1, &envCubeMap);
			glBindTexture(GL_TEXTURE_CUBE_MAP, envCubeMap);
			//给环境立方贴图预留内存
			for (unsigned int i = 0; i < 6; i++)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB16F, 512, 512, 0, GL_RGB, GL_FLOAT, nullptr);
			}
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			QMatrix4x4 captureProjection;
			captureProjection.perspective(90.0f, 1.0f, 0.1f, 10.0f);
			QMatrix4x4 captureViews[6];
			captureViews[0].lookAt(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 0.0f, 0.0f), QVector3D(0.0f, -1.0f, 0.0f));
			captureViews[1].lookAt(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(-1.0f, 0.0f, 0.0f), QVector3D(0.0f, -1.0f, 0.0f));
			captureViews[2].lookAt(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f));
			captureViews[3].lookAt(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, -1.0f, 0.0f), QVector3D(0.0f, 0.0f, -1.0f));
			captureViews[4].lookAt(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.0f, -1.0f, 0.0f));
			captureViews[5].lookAt(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, -1.0f), QVector3D(0.0f, -1.0f, 0.0f));
			envTocube_shader.bind();
			envTocube_shader.setUniformValue("equirectangularMap", 0);
			envTocube_shader.setUniformValue("projection", captureProjection);
			//将hdr贴图转换为立方贴图
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, hdrTexture);
			glViewport(0, 0, 512, 512);
			glBindFramebuffer(GL_FRAMEBUFFER, captureFBO);
			for (unsigned int i = 0; i < 6; i++)
			{
				envTocube_shader.setUniformValue("view", captureViews[i]);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, envCubeMap, 0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				renderCube();
			}
			envTocube_shader.release();
			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			glGenTextures(1, &irradianceMap);
			glBindTexture(GL_TEXTURE_CUBE_MAP, irradianceMap);
			for (unsigned int i = 0; i < 6; i++)
			{
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB16F, 32, 32, 0, GL_RGB, GL_FLOAT, nullptr);
			}
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBindFramebuffer(GL_FRAMEBUFFER, captureFBO);
			glBindRenderbuffer(GL_RENDERBUFFER, captureRBO);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, 32, 32);
			irradiance_shader.bind();
			irradiance_shader.setUniformValue("environmentMap", 0);
			irradiance_shader.setUniformValue("projection", captureProjection);
			//预计算漫反射辐照
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_CUBE_MAP, envCubeMap);
			glViewport(0, 0, 32, 32);
			glBindFramebuffer(GL_FRAMEBUFFER, captureFBO);
			for (unsigned int i = 0; i < 6; i++)
			{
				irradiance_shader.setUniformValue("view", captureViews[i]);
				glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, irradianceMap, 0);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				renderCube();
			}
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
			isFirstLoadEnv = false;
		}
	}

	//正常的渲染
	glViewport(0, 0, width(), height());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//把光照信息和相机信息传给shader
	shaderProgram->bind();
	shaderProgram->setUniformValue("cameraPos", camera.get_position());
	if (isEnvON)
	{
		shaderProgram->setUniformValue("irradianceMap", 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, irradianceMap);
	}
	////平行光信息
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
	//点光源信息
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
	//聚光信息
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
	//绘制场景
	for (int i = 0; i < sceneObjects.size(); i++)
	{
		if (sceneObjects[i] == NULL)
		{
			continue;
		}
		sceneObjects[i]->Draw(shaderProgram);
	}
	if (isEnvON)
	{
		//绘制天空盒
		background_shader.bind();
		QMatrix4x4 projection;
		projection.perspective(camera.get_zoom(), (float)width() / (float)height(), 0.1f, 100.0f);
		background_shader.setUniformValue("projection", projection);
		background_shader.setUniformValue("view", camera.ViewMatrix());
		background_shader.setUniformValue("environmentMap", 0);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, envCubeMap);
		renderCube();
		background_shader.release();
	}
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
	float deltaY = event->pos().y() - lastY;
	lastY = event->y();
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

//初始化着色器
void Render::InitShaderProgram(std::string vertexPath, std::string fragmentPath, QOpenGLShaderProgram& targetShader)
{
	bool success = targetShader.addShaderFromSourceFile(QOpenGLShader::Vertex, vertexPath.c_str());
	if (!success)
	{
		qDebug() << "load vertex shader failed!" << targetShader.log();
		return;
	}
	success = targetShader.addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentPath.c_str());
	if (!success)
	{
		qDebug() << "load frag shader failed!" << targetShader.log();
		return;
	}
	success = targetShader.link();
	if (!success)
	{
		qDebug() << "shader program link failed" << targetShader.log();
		return;
	}
}

//渲染预处理数据用的立方体
void Render::renderCube()
{
	if (cubeVAO == 0)
	{
		float vertices[] = {
			// back face
			-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
			 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
			 1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
			 1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
			-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
			-1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f, // top-left
			// front face
			-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
			 1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f, // bottom-right
			 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
			 1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
			-1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f, // top-left
			-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
			// left face
			-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
			-1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-left
			-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
			-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
			-1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-right
			-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
			// right face
			 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
			 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
			 1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-right         
			 1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
			 1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
			 1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left     
			// bottom face
			-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
			 1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // top-left
			 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
			 1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
			-1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
			-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
			// top face
			-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
			 1.0f,  1.0f , 1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
			 1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f, // top-right     
			 1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
			-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
			-1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left        
		};
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);
		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glBindVertexArray(cubeVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	glBindVertexArray(cubeVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

//设置选中物体
void Render::set_targetObject(RenderObject* value)
{
	target = value;
}

RenderObject* Render::get_targetObject()
{
	return target;
}

bool Render::get_textureON()
{
	return textureON;
}

bool Render::get_PBRMaterialON()
{
	return PBRMaterialON;
}

//添加物体

RenderObject* Render::AddCube()
{
	Cube* cube = new Cube(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), this);
	sceneObjects.push_back(cube);
	return cube;
}

RenderObject* Render::AddSphere()
{
	Sphere* sphere = new Sphere(QVector3D(0.0f, 0.0f, 0.0f), QVector3D(1.0f, 1.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), this);
	sceneObjects.push_back(sphere);
	return sphere;
}

void Render::AddModel(std::string path, PBR_Renderer* mainwindow)
{
	isLoadModel = true;
	loadModelPath = path;
	p_mainwindow = mainwindow;
}

//改变属性的槽函数
//位置改变
void Render::ChangePositionX(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D position = target->get_position();
	position.setX(text.toFloat());
	target->set_position(position);
}

void Render::ChangePositionY(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D position = target->get_position();
	position.setY(text.toFloat());
	target->set_position(position);
}

void Render::ChangePositionZ(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D position = target->get_position();
	position.setZ(text.toFloat());
	target->set_position(position);
}

//大小改变
void Render::ChangeScaleX(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D scale = target->get_scale();
	scale.setX(text.toFloat());
	target->set_scale(scale);
}

void Render::ChangeScaleY(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D scale = target->get_scale();
	scale.setY(text.toFloat());
	target->set_scale(scale);
}

void Render::ChangeScaleZ(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D scale = target->get_scale();
	scale.setZ(text.toFloat());
	target->set_scale(scale);
}

//旋转改变
void Render::ChangeRotationX(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D rotation = target->get_rotation();
	rotation.setX(text.toFloat());
	target->set_rotation(rotation);
}

void Render::ChangeRotationY(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D rotation = target->get_rotation();
	rotation.setY(text.toFloat());
	target->set_rotation(rotation);
}

void Render::ChangeRotationZ(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D rotation = target->get_rotation();
	rotation.setZ(text.toFloat());
	target->set_rotation(rotation);
}

//颜色改变
void Render::ChangeColorR(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D color = target->get_color();
	color.setX(text.toFloat());
	target->set_color(color);
}

void Render::ChangeColorG(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D color = target->get_color();
	color.setY(text.toFloat());
	target->set_color(color);
}

void Render::ChangeColorB(const QString& text)
{
	if (target == NULL)
		return;
	QVector3D color = target->get_color();
	color.setZ(text.toFloat());
	target->set_color(color);
}

//金属度改变
void Render::ChangeMetallic(const QString& text)
{
	if (target == NULL)
		return;
	target->set_metallic(text.toFloat());
}

//粗糙度改变
void Render::ChangeRoughness(const QString& text)
{
	if (target == NULL)
		return;
	target->set_roughness(text.toFloat());
}

//ao改变
void Render::ChangeAO(const QString& text)
{
	if (target == NULL)
		return;
	target->set_ao(text.toFloat());
}

//功能开关
void Render::SettextureON(bool value)
{
	textureON = value;
}

void Render::SetPBRMaterialON(bool value)
{
	PBRMaterialON = value;
}