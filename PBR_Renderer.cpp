#include "PBR_Renderer.h"
#include "Sphere.h"
#include "Cube.h"


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
	//���ܿ���
	connect(ui.actionPBRMaterial, &QAction::triggered, ui.render, &Render::SetPBRMaterialON);  //PBR���ʹ���
	connect(ui.actionPBRMaterial, &QAction::triggered, ui.property, &Property::SetProperties);
	//����������¼�
	connect(ui.treeView, &QTreeView::clicked, this, &PBR_Renderer::ShowProperties); //������ʾѡ�����������
	//��ѧ�ĵ���ʾ
	connect(ui.actionPartone, &QAction::triggered, this, &PBR_Renderer::ShowPartone);
}

void PBR_Renderer::AddSphere()
{
	std::string amount = std::to_string(sphere_num++);
	QString text(("Sphere" + amount).c_str());
	QStandardItem* sphere = new QStandardItem(text);
	sphere->setData(QVariant(ui.render->AddSphere())); //����Ӧ���������洢��item��
	sceneTree->appendRow(sphere);
}

void PBR_Renderer::AddCube()
{
	std::string amount = std::to_string(cube_num++);
	QString text(("Cube" + amount).c_str());
	QStandardItem* cube = new QStandardItem(text);
	cube->setData(QVariant(ui.render->AddCube()));  //����Ӧ���������洢��item��
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

//��ѧ��һ����
void PBR_Renderer::ShowPartone()
{
	partone = new StudyResourse(this, 1);
	partone->setModal(false);
	partone->show();
}