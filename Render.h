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
	void SetLightUI(int i);

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
	void AddEnviromentTex(std::string path);
	std::vector<PointLight>& get_pointLights();
	std::vector<SpotLight>& get_spotLights();


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
	void SetIndirectDiffuseON(bool value);
	void SetIndirectSpecularON(bool value);
	void SetPLightONOFF1(bool value);
	void SetPLightONOFF2(bool value);
	void SetSLightONOFF(bool value);
	void SetPlightPositionX1(const QString& text);
	void SetPlightPositionY1(const QString& text);
	void SetPlightPositionZ1(const QString& text);
	void SetPlightPositionX2(const QString& text);
	void SetPlightPositionY2(const QString& text);
	void SetPlightPositionZ2(const QString& text);
	void SetPlightColorR1(const QString& text);
	void SetPlightColorG1(const QString& text);
	void SetPlightColorB1(const QString& text);
	void SetPlightColorR2(const QString& text);
	void SetPlightColorG2(const QString& text);
	void SetPlightColorB2(const QString& text);
	void SetSlightPositionX(const QString& text);
	void SetSlightPositionY(const QString& text);
	void SetSlightPositionZ(const QString& text);
	void SetSlightColorR(const QString& text);
	void SetSlightColorG(const QString& text);
	void SetSlightColorB(const QString& text);
	void SetSlightDirectionX(const QString& text);
	void SetSlightDirectionY(const QString& text);
	void SetSlightDirectionZ(const QString& text);

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
	//���Ʋ���
	Ui::Render ui;
	QOpenGLShaderProgram* shaderProgram;
	QOpenGLShaderProgram traditonal_notex_shader;   //��ͳ����shader
	QOpenGLShaderProgram traditonal_tex_shader;     //��ͳ���մ���ͼshader
	QOpenGLShaderProgram pbr_notex_shader;          //pbr����ͼshader
	QOpenGLShaderProgram pbr_tex_shader;            //pbr����ͼshader
	QOpenGLShaderProgram envTocube_shader;          //hdr��ͼת������ͼshader
	QOpenGLShaderProgram irradiance_shader;         //��������ռ���shader
	QOpenGLShaderProgram background_shader;         //��պ���Ⱦshader
	QOpenGLShaderProgram envPBR_notex_shader;       //ʹ�û�����ͼ��pbr shader
	QOpenGLShaderProgram prefilter_shader;          //Ԥ�˲�HDR������ͼ shader
	QOpenGLShaderProgram brdf_shader;               //Ԥ����brdf��ͼ shader
	QOpenGLShaderProgram envPBR_withTexture_shader;      //���м���������PBR shader
	QOpenGLShaderProgram final_notex_shader;
	QOpenGLShaderProgram final_withtexture_shader;              //��Ӿ��������shader
	//QOpenGLShaderProgram depth_texture;              //�������ͼshader

	void InitShaderProgram(std::string vertexPath, std::string fragmentPath, QOpenGLShaderProgram& targetShader);          //��ʼ����ɫ��
	void Preirradiance();   //��ӹ������������Ԥ����  
	void Prereflect();      //��ӹ��վ��淴�����Ԥ����
	//void Depth();           //�������ͼ
	void renderCube();      //Ԥ������������
	void renderQuad();      //Ԥ������ƽ��
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
	//��������
	DirectionLight directionLight;
	std::vector<PointLight> pointLights;
	std::vector<SpotLight> spotLights;
	RenderObject* target;
	//��պ���IBL��ز���
	bool isFirstLoadEnv;
	std::string hdrTexturePath;
	unsigned int captureFBO;   //�м仺��֡
	unsigned int captureRBO;
	unsigned int hdrTexture;    //hdr��ͼ
	unsigned int envCubeMap;    //hdrת����Ļ�����ͼ
	unsigned int irradianceMap; //Ԥ��������������ͼ	
	unsigned int prefilterMap;
	unsigned int brdfLUTTexture;
	bool isPreReflectON;
	bool isFirstPreCalc;
	//���ܽ�������
	bool isPBRMaterialON;
	bool isTextureON;
	bool isEnvON;
	//����ģ��
	std::string loadModelPath;
	//test
	bool isLoadModel;
	PBR_Renderer* p_mainwindow;
};

