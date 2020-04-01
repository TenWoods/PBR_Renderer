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

class Render : public QOpenGLWidget, public QOpenGLFunctions_4_4_Core
{
	Q_OBJECT

public:
	Render(QWidget *parent = Q_NULLPTR);
	~Render();
	Camera camera;
	void set_focusObject(int i);
	RenderObject* get_focusObject();
	bool get_textureON();
	bool get_PBRMaterialON();

public slots:
	int AddCube();
	int AddSphere();
	int AddModel(std::string path);
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
	QOpenGLShaderProgram traditonal_notex_shader;
	QOpenGLShaderProgram traditonal_tex_shader;
	QOpenGLShaderProgram pbr_notex_shader;
	QOpenGLShaderProgram pbr_tex_shader;
	float lastFrame;
	float deltaTime;
	QTime time;
	float lastX;
	float lastY;
	bool isFirstMouse;
	bool isRightMousePress;
	//场景数据
	std::vector<RenderObject*> sceneObjects;
	DirectionLight directionLight;
	std::vector<PointLight> pointLights;
	std::vector<SpotLight> spotLights;
	RenderObject* focusObject;
	//功能解锁参数
	bool PBRMaterialON;
	bool textureON;
	//加载模型
	std::string loadModelPath;
	//test
	bool isLoadModel;
};

