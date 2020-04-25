#pragma once

#include <QtWidgets/QMainWindow>
#include <qstandarditemmodel.h>
#include <string>
#include "ui_PBR_Renderer.h"
#include "Property.h"
#include "StudyResourse.h"

class PBR_Renderer : public QMainWindow
{
	Q_OBJECT

public:
	PBR_Renderer(QWidget *parent = Q_NULLPTR);
	void SetModelTree(Model* model);
public slots:
	void AddSphere();  //���������
	void AddCube();  //�������������
	void ShowProperties(const QModelIndex& index);  //��ʾ����
	void ShowPartone(); //��ʾ��һ���ֽ�ѧ
	void UnlockMaterial();
	void UnlockDiffuse();
	void UnlockSpecular();
	void AddModel();
	void AddEnviromentTexture();
	
private:
	Ui::PBR_RendererClass ui;
	QStandardItemModel* sceneTree;
	QActionGroup* materialGroup;
	int sphere_num;
	int cube_num;
	StudyResourse* partone;
};
