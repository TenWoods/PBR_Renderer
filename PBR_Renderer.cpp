#include "PBR_Renderer.h"
#include "Sphere.h"
#include "Cube.h"


PBR_Renderer::PBR_Renderer(QWidget* parent) : QMainWindow(parent), sphere_num(0), cube_num(0)
{
	ui.setupUi(this);
	setWindowIcon(QIcon(QString("icon.png")));

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
	//教学文档显示
	connect(ui.actionPartone, &QAction::triggered, this, &PBR_Renderer::ShowPartone);
}

void PBR_Renderer::AddSphere()
{
	std::string amount = std::to_string(sphere_num++);
	QString text(("Sphere" + amount).c_str());
	QStandardItem* sphere = new QStandardItem(text);
	sphere->setData(QVariant(ui.render->AddSphere())); //将对应物体索引存储到item中
	sceneTree->appendRow(sphere);
}

void PBR_Renderer::AddCube()
{
	std::string amount = std::to_string(cube_num++);
	QString text(("Cube" + amount).c_str());
	QStandardItem* cube = new QStandardItem(text);
	cube->setData(QVariant(ui.render->AddCube()));  //将对应物体索引存储到item中
	//qDebug() << cube->data().value<int>();
	sceneTree->appendRow(cube);
}

void PBR_Renderer::ShowProperties(const QModelIndex& index)
{
	ui.property->setEnabled(true);
	int i = sceneTree->itemFromIndex(index)->data().value<int>();
	ui.render->set_focusObject(i);
	//qDebug() << i;
	ui.property->SetProperties();
}

//教学第一部分
void PBR_Renderer::ShowPartone()
{
	partone = new StudyResourse(this, 1);
	partone->setModal(false);
	partone->show();
}