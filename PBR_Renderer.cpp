#include <algorithm>
#include "PBR_Renderer.h"
#include "Sphere.h"
#include "Cube.h"
#include "Model.h"


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
	connect(ui.actionLoadModel, &QAction::triggered, this, &PBR_Renderer::AddModel);
	//功能开启
	connect(ui.actionPBRMaterial, &QAction::triggered, ui.render, &Render::SetPBRMaterialON);  //PBR材质功能
	//connect(ui.actionPBRMaterial, &QAction::triggered, ui.property, &Property::SetProperties);
	connect(ui.actionindirectDiffuse, &QAction::triggered, ui.render, &Render::SetIndirectDiffuseON);  //间接漫反射功能
	connect(ui.actionIBL, &QAction::triggered, ui.render, &Render::SetIndirectSpecularON);             //间接镜面反射功能
	//场景栏点击事件
	connect(ui.treeView, &QTreeView::clicked, this, &PBR_Renderer::ShowProperties); //单击显示选中物体的属性
	//教学文档显示
	connect(ui.actionPartone, &QAction::triggered, this, &PBR_Renderer::ShowPartone);
	//meshUI生成信号
	connect(ui.render, &Render::SetMeshUI, this, &PBR_Renderer::SetModelTree);
	//添加环境贴图
	connect(ui.envButton, &QPushButton::clicked, this, &PBR_Renderer::AddEnviromentTexture);
	//光源设置
	connect(ui.render, &Render::SetLightUI, this, &PBR_Renderer::SetLightData);
	//1号
	connect(ui.radioButton_pointlight1, &QRadioButton::clicked, ui.render, &Render::SetPLightONOFF1);
	connect(ui.lineEdit_p1px, &QLineEdit::textChanged, ui.render, &Render::SetPlightPositionX1);
	connect(ui.lineEdit_p1py, &QLineEdit::textChanged, ui.render, &Render::SetPlightPositionY1);
	connect(ui.lineEdit_p1pz, &QLineEdit::textChanged, ui.render, &Render::SetPlightPositionZ1);
	connect(ui.lineEdit_p1cr, &QLineEdit::textChanged, ui.render, &Render::SetPlightColorR1);
	connect(ui.lineEdit_p1cg, &QLineEdit::textChanged, ui.render, &Render::SetPlightColorG1);
	connect(ui.lineEdit_p1cb, &QLineEdit::textChanged, ui.render, &Render::SetPlightColorB1);
	//2号
	connect(ui.radioButton_pointlight2, &QRadioButton::clicked, ui.render, &Render::SetPLightONOFF2);
	connect(ui.lineEdit_p2px, &QLineEdit::textChanged, ui.render, &Render::SetPlightPositionX2);
	connect(ui.lineEdit_p2py, &QLineEdit::textChanged, ui.render, &Render::SetPlightPositionY2);
	connect(ui.lineEdit_p2pz, &QLineEdit::textChanged, ui.render, &Render::SetPlightPositionZ2);
	connect(ui.lineEdit_p2cr, &QLineEdit::textChanged, ui.render, &Render::SetPlightColorR2);
	connect(ui.lineEdit_p2cg, &QLineEdit::textChanged, ui.render, &Render::SetPlightColorG2);
	connect(ui.lineEdit_p2cb, &QLineEdit::textChanged, ui.render, &Render::SetPlightColorB2);
}

void PBR_Renderer::SetModelTree(Model* model)
{
	//qDebug() << "?";
	QStandardItem* model_item = new QStandardItem(QString("model"));
	QVariant model_data = QVariant::fromValue((void*)model);
	model_item->setData(model_data);
	int size = model->get_meshsize();
	for (int i = 0; i < size; i++)
	{
		std::string amount = std::to_string(i);
		QStandardItem* mesh = new QStandardItem(QString(("mesh" + amount).c_str()));
		QVariant mesh_data = QVariant::fromValue((void*)model->get_meshpointer(i));
		mesh->setData(mesh_data);
		model_item->appendRow(mesh);
	}
	sceneTree->appendRow(model_item);
}

//槽函数
void PBR_Renderer::AddSphere()
{
	std::string amount = std::to_string(sphere_num++);
	QString text(("Sphere" + amount).c_str());
	QStandardItem* sphere = new QStandardItem(text);
	QVariant sphere_data = QVariant::fromValue((void*)ui.render->AddSphere());
	sphere->setData(sphere_data);         //将对应物体指针存储到item中
	//sphere->setData(QVariant(ui.render->AddSphere())); //将对应物体索引存储到item中
	sceneTree->appendRow(sphere);
}

void PBR_Renderer::AddCube()
{
	std::string amount = std::to_string(cube_num++);
	QString text(("Cube" + amount).c_str());
	QStandardItem* cube = new QStandardItem(text);
	QVariant cube_data = QVariant::fromValue((void*)ui.render->AddCube());
	cube->setData(cube_data);         //将对应物体指针存储到item中
	//cube->setData(QVariant(ui.render->AddCube()));  
	sceneTree->appendRow(cube);
	//cube->appendRow(new QStandardItem("test")); 
}

void PBR_Renderer::AddModel()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("选择模型地址"), "/", QStringLiteral("模型文件 (*.obj);; 所有文件 (*.*);;"));
	if (path.isEmpty())
	{
		return;
	}
	ui.render->AddModel(path.toStdString(), this);
}

void PBR_Renderer::ShowProperties(const QModelIndex& index)
{
	ui.property->setEnabled(true);
	RenderObject* target = (RenderObject*)sceneTree->itemFromIndex(index)->data().value<void*>();
	ui.render->set_targetObject(target);
	ui.property->SetProperties();
}

//教学第一部分
void PBR_Renderer::ShowPartone()
{
	partone = new StudyResourse(this, 1, this);
	partone->setWindowTitle(QStringLiteral("PBR材质与直接光照教学"));
	partone->setModal(false);
	partone->show();
}

//解锁PBR材质功能
void PBR_Renderer::UnlockMaterial()
{
	ui.actionPBRMaterial->setEnabled(true);
}

//解锁间接漫反射功能
void PBR_Renderer::UnlockDiffuse()
{
	ui.actionindirectDiffuse->setEnabled(true);
}

//解锁直接反射功能
void PBR_Renderer::UnlockSpecular()
{
	ui.actionIBL->setEnabled(true);
}

//添加环境贴图
void PBR_Renderer::AddEnviromentTexture()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("选择环境贴图"), "/", QStringLiteral("环境贴图文件 (*.hdr);;所有文件 (*.*);;"));
	if (path.isEmpty())
		return;
	ui.render->AddEnviromentTex(path.toStdString());
}

void PBR_Renderer::SetLightData(int i)
{
	if (i == 0)
	{
		ui.lineEdit_p1px->setText(QString("%1").arg(ui.render->get_pointLights()[0].get_position().x()));
		ui.lineEdit_p1py->setText(QString("%1").arg(ui.render->get_pointLights()[0].get_position().y()));
		ui.lineEdit_p1pz->setText(QString("%1").arg(ui.render->get_pointLights()[0].get_position().z()));
		ui.lineEdit_p1cr->setText(QString("%1").arg(ui.render->get_pointLights()[0].get_lightColor().x()));
		ui.lineEdit_p1cg->setText(QString("%1").arg(ui.render->get_pointLights()[0].get_lightColor().y()));
		ui.lineEdit_p1cb->setText(QString("%1").arg(ui.render->get_pointLights()[0].get_lightColor().z()));
	}
	else if (i == 1)
	{
		ui.lineEdit_p2px->setText(QString("%1").arg(ui.render->get_pointLights()[1].get_position().x()));
		ui.lineEdit_p2py->setText(QString("%1").arg(ui.render->get_pointLights()[1].get_position().y()));
		ui.lineEdit_p2pz->setText(QString("%1").arg(ui.render->get_pointLights()[1].get_position().z()));
		ui.lineEdit_p2cr->setText(QString("%1").arg(ui.render->get_pointLights()[1].get_lightColor().x()));
		ui.lineEdit_p2cg->setText(QString("%1").arg(ui.render->get_pointLights()[1].get_lightColor().y()));
		ui.lineEdit_p2cb->setText(QString("%1").arg(ui.render->get_pointLights()[1].get_lightColor().z()));
	}
}