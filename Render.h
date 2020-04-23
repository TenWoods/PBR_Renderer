#pragma once
#include <QOpenGLWidget>
#include <qopenglfunctions_4_4_core.h>
#include <qopenglshaderprogram.h>
#include <qkeyevent.h>
#include <qwindowdefs.h>
#include <QTime>
#include <qmath.h>
#include <queue>
#include "ui_Render.h"
#include "Camera.h"
#include "Light.h"
#include "RenderObject.h"
#include "Cube.h"
#include "Sphere.h"
#include "Model.h"

class PBR_Renderer;

class Render : public QOpenGLWidget, public QOpenGLFunctions_4_4_Core
{
	Q_OBJECT

signals:
	void SetMeshUI(Model* pointer);

public:
	Render(QWidget *parent = Q_NULLPTR);
	~Render();
	Camera camera;
	std::vector<RenderObject*> sceneObjects;
	void set_targetObject(RenderObject* value);
	RenderObject* get_targetObject();
	bool get_textureON();
	bool get_PBRMaterialON();
	RenderObject* AddCube();
	RenderObject* AddSphere();
	void AddModel(std::string path, PBR_Renderer* mainwindow);


public slots:
	void ChangePositionX(const QString& text);
	void ChangePositionY(const QString& text);
	void ChangePositionZ(const QString& text);
	void ChangeScaleX(const QString& text);
	void ChangeScaleY(const QString& text);
	void ChangeScaleZ(const QString& text);
	void ChangeRotationX(const QString& text);
	void ChangeRotationY(const QString& text);
	void ChangeRotationZ(const QString& text);
	void ChangeColorR(const QString& text);
	void ChangeColorG(const QString& text);
	void ChangeColorB(const QString& text);
	void ChangeMetallic(const QString& text);
	void ChangeRoughness(const QString& text);
	void ChangeAO(const QString& text);
	void SettextureON(bool value);
	void SetPBRMaterialON(bool value);
	void SetIrradianceON(bool value);

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
	//绘制参数
	Ui::Render ui;
	QOpenGLShaderProgram* shaderProgram;
	QOpenGLShaderProgram traditonal_notex_shader;   //传统光照shader
	QOpenGLShaderProgram traditonal_tex_shader;     //传统光照带贴图shader
	QOpenGLShaderProgram pbr_notex_shader;          //pbr无贴图shader
	QOpenGLShaderProgram pbr_tex_shader;            //pbr有贴图shader
	QOpenGLShaderProgram envTocube_shader;          //hdr贴图转立方贴图shader
	QOpenGLShaderProgram irradiance_shader;         //漫反射辐照计算shader
	QOpenGLShaderProgram background_shader;         //天空盒渲染shader
	QOpenGLShaderProgram envPBR_notex_shader;       //使用环境贴图的pbr shader
	QOpenGLShaderProgram prefilter_shader;          //预滤波HDR环境贴图 shader
	QOpenGLShaderProgram brdf_shader;               //预计算brdf贴图 shader

	void InitShaderProgram(std::string vertexPath, std::string fragmentPath, QOpenGLShaderProgram& targetShader);          //初始化着色器
	void Preirradiance();   //间接光照漫反射辐照预计算  
	void Prereflect();      //间接光照镜面反射辐照预计算
	void renderCube();      //预计算用立方体
	void renderQuad();      //预计算用平面
	unsigned int cubeVAO;
	unsigned int cubeVBO;
	unsigned int quadVAO;
	unsigned int quadVBO;
	float lastFrame;
	float deltaTime;
	QTime time;
	float lastX;
	float lastY;
	bool isFirstMouse;
	bool isRightMousePress;
	//场景数据
	DirectionLight directionLight;
	std::vector<PointLight> pointLights;
	std::vector<SpotLight> spotLights;
	RenderObject* target;
	//天空盒与IBL相关参数
	bool isFirstLoadEnv;
	std::string hdrTexturePath;
	unsigned int captureFBO;   //中间缓冲帧
	unsigned int captureRBO;
	unsigned int hdrTexture;    //hdr贴图
	unsigned int envCubeMap;    //hdr转换后的环境贴图
	unsigned int irradianceMap; //预计算的漫反射辐照图	
	unsigned int prefilterMap;
	unsigned int brdfLUTTexture;
	bool isPreReflectON;
	bool isFirstPreCalc;
	//功能解锁参数
	bool isPBRMaterialON;
	bool isTextureON;
	bool isEnvON;
	//加载模型
	std::string loadModelPath;
	//test
	bool isLoadModel;
	PBR_Renderer* p_mainwindow;
};

