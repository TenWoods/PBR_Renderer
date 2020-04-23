#include <algorithm>
#include "PBR_Renderer.h"
#include "Sphere.h"
#include "Cube.h"
#include "Model.h"


PBR_Renderer::PBR_Renderer(QWidget* parent) : QMainWindow(parent), sphere_num(0), cube_num(0)
{
	ui.setupUi(this);
	setWindowIcon(QIcon(QString("icon.png")));

	//��ʼ����������UI
	sceneTree = new QStandardItemModel(ui.treeView);
	sceneTree->setHorizontalHeaderLabels(QStringList() << QStringLiteral("������"));
	ui.treeView->setModel(sceneTree);
	ui.property->set_render(ui.render);
	ui.property->SetConnection();
	ui.property->setEnabled(false);
	//�˵���������
	connect(ui.actionsphere, &QAction::triggered, this, &PBR_Renderer::AddSphere); //����������
	connect(ui.actioncube, &QAction::triggered, this, &PBR_Renderer::AddCube);  //��������������
	connect(ui.actionLoadModel, &QAction::triggered, this, &PBR_Renderer::AddModel);
	//���ܿ���
	connect(ui.actionPBRMaterial, &QAction::triggered, ui.render, &Render::SetPBRMaterialON);  //PBR���ʹ���
	//connect(ui.actionPBRMaterial, &QAction::triggered, ui.property, &Property::SetProperties);
	//����������¼�
	connect(ui.treeView, &QTreeView::clicked, this, &PBR_Renderer::ShowProperties); //������ʾѡ�����������
	//��ѧ�ĵ���ʾ
	connect(ui.actionPartone, &QAction::triggered, this, &PBR_Renderer::ShowPartone);
	//meshUI�����ź�
	connect(ui.render, &Render::SetMeshUI, this, &PBR_Renderer::SetModelTree);
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

//�ۺ���
void PBR_Renderer::AddSphere()
{
	std::string amount = std::to_string(sphere_num++);
	QString text(("Sphere" + amount).c_str());
	QStandardItem* sphere = new QStandardItem(text);
	QVariant sphere_data = QVariant::fromValue((void*)ui.render->AddSphere());
	sphere->setData(sphere_data);         //����Ӧ����ָ��洢��item��
	//sphere->setData(QVariant(ui.render->AddSphere())); //����Ӧ���������洢��item��
	sceneTree->appendRow(sphere);
}

void PBR_Renderer::AddCube()
{
	std::string amount = std::to_string(cube_num++);
	QString text(("Cube" + amount).c_str());
	QStandardItem* cube = new QStandardItem(text);
	QVariant cube_data = QVariant::fromValue((void*)ui.render->AddCube());
	cube->setData(cube_data);         //����Ӧ����ָ��洢��item��
	//cube->setData(QVariant(ui.render->AddCube()));  
	sceneTree->appendRow(cube);
	cube->appendRow(new QStandardItem("test"));  //TODO:test
}

void PBR_Renderer::AddModel()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ��ģ�͵�ַ"), "/", QStringLiteral("ģ���ļ� (*.obj);; �����ļ� (*.*);;"));
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

//��ѧ��һ����
void PBR_Renderer::ShowPartone()
{
	partone = new StudyResourse(this, 1, this);
	partone->setWindowTitle(QStringLiteral("PBR������ֱ�ӹ��ս�ѧ"));
	partone->setModal(false);
	partone->show();
}

void PBR_Renderer::UnlockMaterial()
{
	ui.actionPBRMaterial->setEnabled(true);
}

