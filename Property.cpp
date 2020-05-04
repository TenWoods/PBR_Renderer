#include "Property.h"
#include "Render.h"

Property::Property(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//�ڲ����������
	//metallic��
	connect(ui.metallicSlider, &QSlider::sliderMoved, this, &Property::MetallicEditFromSlider);
	connect(ui.metallicEdit, &QLineEdit::textChanged, this, &Property::MetallicSliderFromEdit);
	//roughness��
	connect(ui.roughnessSlider, &QSlider::sliderMoved, this, &Property::RoughnessEditFromSlider);
	connect(ui.roughnessEdit, &QLineEdit::textChanged, this, &Property::RoughnessSliderFromEdit);
	//ao��
	connect(ui.aoSlider, &QSlider::sliderMoved, this, &Property::AOEditFromSlider);
	connect(ui.aoEdit, &QLineEdit::textChanged, this, &Property::AOSliderFromEdit);
	//��ͼ��������
	connect(ui.diffuseButton, &QPushButton::clicked, this, &Property::SetDiffuseButtonON);
	connect(ui.normalButton, &QPushButton::clicked, this, &Property::SetNormalButtonON);
	connect(ui.metallicButton, &QPushButton::clicked, this, &Property::SetMetallicButtonON);
	connect(ui.roughnessButton, &QPushButton::clicked, this, &Property::SetRoughnessButtonON);
	connect(ui.AOButton, &QPushButton::clicked, this, &Property::SetAOButtonON);
}

Property::~Property()
{
}

void Property::SetConnection()
{
	//ʵʱ�ı�λ��
	connect(ui.px, &QLineEdit::textChanged, render, &Render::ChangePositionX);
	connect(ui.py, &QLineEdit::textChanged, render, &Render::ChangePositionY);
	connect(ui.pz, &QLineEdit::textChanged, render, &Render::ChangePositionZ);
	//ʵʱ�ı��С
	connect(ui.sx, &QLineEdit::textChanged, render, &Render::ChangeScaleX);
	connect(ui.sy, &QLineEdit::textChanged, render, &Render::ChangeScaleY);
	connect(ui.sz, &QLineEdit::textChanged, render, &Render::ChangeScaleZ);
	//ʵʱ��ת
	connect(ui.rx, &QLineEdit::textChanged, render, &Render::ChangeRotationX);
	connect(ui.ry, &QLineEdit::textChanged, render, &Render::ChangeRotationY);
	connect(ui.rz, &QLineEdit::textChanged, render, &Render::ChangeRotationZ);
	//ʵʱ������ɫ
	connect(ui.colorR, &QLineEdit::textChanged, render, &Render::ChangeColorR);
	connect(ui.colorG, &QLineEdit::textChanged, render, &Render::ChangeColorG);
	connect(ui.colorB, &QLineEdit::textChanged, render, &Render::ChangeColorB);
	//�����Ƿ�ʹ����ͼ
	connect(ui.textureonoffButton, &QRadioButton::clicked, render, &Render::SettextureON);
	connect(ui.textureonoffButton, &QRadioButton::clicked, this, &Property::SetProperties);
	//ʵʱ����metallic,roughness,ao
	connect(ui.metallicEdit, &QLineEdit::textChanged, render, &Render::ChangeMetallic);
	connect(ui.roughnessEdit, &QLineEdit::textChanged, render, &Render::ChangeRoughness);
	connect(ui.aoEdit, &QLineEdit::textChanged, render, &Render::ChangeAO);
}

void Property::SetProperties()
{
	if (render == NULL)
	{
		return;
	}
	//���ݹ��ܿ��ų̶ȿ��ŵ�����
	if (render->get_PBRMaterialON())  //����pbr���ʹ���
	{
		if (render->get_textureON())  //����ͼ
		{
			ui.metallicWidget->setEnabled(false);
			ui.roughnessWidget->setEnabled(false);
			ui.aoWidget->setEnabled(false);
			ui.metallictexWidget->setEnabled(true);
			ui.roughnesstexWidget->setEnabled(true);
			ui.aotexWidget->setEnabled(true);
			//TODO: ��ͼԤ��
		}
		else  //����ͼ
		{
			ui.metallicWidget->setEnabled(true);
			ui.roughnessWidget->setEnabled(true);
			ui.aoWidget->setEnabled(true);
			ui.metallictexWidget->setEnabled(false);
			ui.roughnesstexWidget->setEnabled(false);
			ui.aotexWidget->setEnabled(false);
		}
	}
	else  //δ����pbr����
	{
		ui.metallicWidget->setEnabled(false);
		ui.roughnessWidget->setEnabled(false);
		ui.aoWidget->setEnabled(false);
		ui.metallictexWidget->setEnabled(false);
		ui.roughnesstexWidget->setEnabled(false);
		ui.aotexWidget->setEnabled(false);
	}
	if (render->get_textureON())  //������ͼ����
	{
		ui.diffuseWidget->setEnabled(true);
		ui.normalWidget->setEnabled(true);
		//TODO: ��ͼԤ��
	}
	else
	{
		ui.diffuseWidget->setEnabled(false);
		ui.normalWidget->setEnabled(false);
	}

	//��ֵ����
	RenderObject* target = render->get_targetObject();
	if (target == NULL)
	{
		return;
	}
	//position
	ui.px->setText(QString("%1").arg(target->get_position().x()));
	ui.py->setText(QString("%1").arg(target->get_position().y()));
	ui.pz->setText(QString("%1").arg(target->get_position().z()));
	//scale
	ui.sx->setText((QString("%1").arg(target->get_scale().x())));
	ui.sy->setText((QString("%1").arg(target->get_scale().y())));
	ui.sz->setText((QString("%1").arg(target->get_scale().z())));
	//rotation
	ui.rx->setText((QString("%1").arg(target->get_rotation().x())));
	ui.ry->setText((QString("%1").arg(target->get_rotation().y())));
	ui.rz->setText((QString("%1").arg(target->get_rotation().z())));
	//color
	ui.colorR->setText(QString("%1").arg(target->get_color().x()));
	ui.colorG->setText(QString("%1").arg(target->get_color().y()));
	ui.colorB->setText(QString("%1").arg(target->get_color().z()));
	//metallic,roughness,ao
	ui.metallicSlider->setValue((int)(target->get_metallic() * 100));
	ui.roughnessSlider->setValue((int)(target->get_roughness() * 100));
	ui.aoSlider->setValue((int)(target->get_ao() * 100));
	//������ͼԤ��
	auto textures = target->get_textures();
	for (int i = 0; i < textures.size(); i++)
	{
		QPixmap tex;
		QPixmap fittex;
		switch (textures[i].type)
		{
		case TEXTURE_TYPE::DIFFUSE:
			tex = QPixmap(textures[i].path.c_str());
			fittex = tex.scaled(ui.label_diffuse->size(), Qt::KeepAspectRatio);
			ui.label_diffuse->setPixmap(fittex);
			break;
		case TEXTURE_TYPE::NORMAL:
			tex = QPixmap(textures[i].path.c_str());
			fittex = tex.scaled(ui.label_normal->size(), Qt::KeepAspectRatio);
			ui.label_normal->setPixmap(fittex);
			break;
		case TEXTURE_TYPE::METALLIC:
			tex = QPixmap(textures[i].path.c_str());
			fittex = tex.scaled(ui.label_metallic->size(), Qt::KeepAspectRatio);
			ui.label_metallic->setPixmap(fittex);
			break;
		case TEXTURE_TYPE::ROUGHNESS:
			tex = QPixmap(textures[i].path.c_str());
			fittex = tex.scaled(ui.label_roughness->size(), Qt::KeepAspectRatio);
			ui.label_roughness->setPixmap(fittex);
			break;
		case TEXTURE_TYPE::AO:
			tex = QPixmap(textures[i].path.c_str());
			fittex = tex.scaled(ui.label_ao->size(), Qt::KeepAspectRatio);
			ui.label_ao->setPixmap(fittex);
			break;
		}
	}
}

void Property::set_render(Render* value)
{
	render = value;
}

//�ۺ���
//slider��edit������
void Property::MetallicEditFromSlider(int value)
{
	ui.metallicEdit->setText(QString("%1").arg((float)value / 100.0f));
}

void Property::MetallicSliderFromEdit(const QString& text)
{
	ui.metallicSlider->setValue((int)(text.toFloat() * 100.0f));
}

void Property::RoughnessEditFromSlider(int value)
{
	ui.roughnessEdit->setText(QString("%1").arg((float)value / 100.0f));
}

void Property::RoughnessSliderFromEdit(const QString& text)
{
	ui.roughnessSlider->setValue((int)(text.toFloat() * 100.0f));
}

void Property::AOEditFromSlider(int value)
{
	ui.aoEdit->setText(QString("%1").arg((float)value / 100.0f));
}

void Property::AOSliderFromEdit(const QString& text)
{
	ui.aoSlider->setValue((int)(text.toFloat() * 100.0f));
}
//������ͼ
void Property::SetDiffuseButtonON()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ����������ͼ"), "/", QStringLiteral("��ͼ�ļ� (*.png *.jpg);; �����ļ� (*.*);;"));
	if (path.isEmpty())
		return;
	render->get_targetObject()->AddTexture(path.toStdString(), TEXTURE_TYPE::DIFFUSE);
	QPixmap tex(path);
	QPixmap fittex = tex.scaled(ui.label_diffuse->size(), Qt::KeepAspectRatio);
	ui.label_diffuse->setPixmap(fittex);
}

void Property::SetSpecularButtonON()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ��߹���ͼ"), "/", QStringLiteral("��ͼ�ļ� (*.png *.jpg);; �����ļ� (*.*);;"));
	if (path.isEmpty())
		return;
	render->get_targetObject()->AddTexture(path.toStdString(), TEXTURE_TYPE::SPECULAR);
}

void Property::SetNormalButtonON()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ������ͼ"), "/", QStringLiteral("��ͼ�ļ� (*.png *.jpg);; �����ļ� (*.*);;"));
	if (path.isEmpty())
		return;
	render->get_targetObject()->AddTexture(path.toStdString(), TEXTURE_TYPE::NORMAL);
	QPixmap tex(path);
	QPixmap fittex = tex.scaled(ui.label_normal->size(), Qt::KeepAspectRatio);
	ui.label_normal->setPixmap(fittex);
}

void Property::SetMetallicButtonON()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ���������ͼ"), "/", QStringLiteral("��ͼ�ļ� (*.png *.jpg);; �����ļ� (*.*);;"));
	if (path.isEmpty())
		return;
	render->get_targetObject()->AddTexture(path.toStdString(), TEXTURE_TYPE::METALLIC);
	QPixmap tex(path);
	QPixmap fittex = tex.scaled(ui.label_metallic->size(), Qt::KeepAspectRatio);
	ui.label_metallic->setPixmap(fittex);
}

void Property::SetRoughnessButtonON()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ��ֲڶ���ͼ"), "/", QStringLiteral("��ͼ�ļ� (*.png *.jpg);; �����ļ� (*.*);;"));
	if (path.isEmpty())
		return;
	render->get_targetObject()->AddTexture(path.toStdString(), TEXTURE_TYPE::ROUGHNESS);
	QPixmap tex(path);
	QPixmap fittex = tex.scaled(ui.label_roughness->size(), Qt::KeepAspectRatio);
	ui.label_roughness->setPixmap(fittex);
}

void Property::SetAOButtonON()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ��AO��ͼ"), "/", QStringLiteral("��ͼ�ļ� (*.png *.jpg);; �����ļ� (*.*);;"));
	if (path.isEmpty())
		return;
	render->get_targetObject()->AddTexture(path.toStdString(), TEXTURE_TYPE::AO);
	QPixmap tex(path);
	QPixmap fittex = tex.scaled(ui.label_ao->size(), Qt::KeepAspectRatio);
	ui.label_ao->setPixmap(fittex);
}