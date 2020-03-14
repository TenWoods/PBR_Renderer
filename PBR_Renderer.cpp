#include "PBR_Renderer.h"
#include "Sphere.h"
#include "Cube.h"


PBR_Renderer::PBR_Renderer(QWidget* parent) : QMainWindow(parent), sphere_num(0), cube_num(0)
{
	ui.setupUi(this);
	//初始化场景树的UI
	sceneTree = new QStandardItemModel(ui.treeView);
	sceneTree->setHorizontalHeaderLabels(QStringList() << QStringLiteral("物体名"));
	ui.treeView->setModel(sceneTree);
	ui.property->set_render(ui.render);
	ui.property->SetConnection();
	ui.property->setEnabled(false);
	//菜单栏按键绑定
	connect(ui.actionsphere, &QAction::triggered, this, &PBR_Renderer::AddSphere); //场景生成球
	connect(ui.actioncube, &QAction::triggered, this, &PBR_Renderer::AddCube);  //场景生成立方体
	//功能开启
	connect(ui.actionPBRMaterial, &QAction::triggered, ui.render, &Render::SetPBRMaterialON);  //PBR材质功能
	connect(ui.actionPBRMaterial, &QAction::triggered, ui.property, &Property::SetProperties);
	//场景栏点击事件
	connect(ui.treeView, &QTreeView::clicked, this, &PBR_Renderer::ShowProperties); //单击显示选中物体的属性
}

void PBR_Renderer::AddSphere()
{
	std::string num = std::to_string(sphere_num++);
	QString text(("Sphere" + num).c_str());
	QStandardItem* sphere = new QStandardItem(text);
	sphere->setData(QVariant(ui.render->AddSphere())); //将对应物体索引存储到item中
	sceneTree->appendRow(sphere);
}

void PBR_Renderer::AddCube()
{
	std::string num = std::to_string(cube_num++);
	QString text(("Cube" + num).c_str());
	QStandardItem* cube = new QStandardItem(text);
	cube->setData(QVariant(ui.render->AddCube()));  //将对应物体索引存储到item中
	//qDebug() << cube->data().value<int>();
	sceneTree->appendRow(cube);
}

void PBR_Renderer::ShowProperties(const QModelIndex& index)
{
	ui.property->setEnabled(true);
	ui.render->set_focusObject(index.data().value<int>());
	//qDebug() << index.data().value<int>();
	ui.property->SetProperties();
}