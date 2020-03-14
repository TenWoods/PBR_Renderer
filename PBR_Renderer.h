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
public slots:
	void AddSphere();  //场景添加球
	void AddCube();  //场景添加立方体
	void ShowProperties(const QModelIndex& index);  //显示属性
	void ShowPartone();
private:
	Ui::PBR_RendererClass ui;
	QStandardItemModel* sceneTree;
	QActionGroup* materialGroup;
	int sphere_num;
	int cube_num;
	StudyResourse* partone;
};
