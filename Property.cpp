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
		ui.specularWidget->setEnabled(true);
		ui.normalWidget->setEnabled(true);
		//TODO: ��ͼԤ��
	}
	else
	{
		ui.diffuseWidget->setEnabled(false);
		ui.specularWidget->setEnabled(false);
		ui.normalWidget->setEnabled(false);
	}

	//��ֵ����
	RenderObject* focus = render->get_focusObject();
	if (focus == NULL)
	{
		return;
	}
	//position
	ui.px->setText(QString("%1").arg(focus->get_position().x()));
	ui.py->setText(QString("%1").arg(focus->get_position().y()));
	ui.pz->setText(QString("%1").arg(focus->get_position().z()));
	//scale
	ui.sx->setText((QString("%1").arg(focus->get_scale().x())));
	ui.sy->setText((QString("%1").arg(focus->get_scale().y())));
	ui.sz->setText((QString("%1").arg(focus->get_scale().z())));
	//rotation
	ui.rx->setText((QString("%1").arg(focus->get_rotation().x())));
	ui.ry->setText((QString("%1").arg(focus->get_rotation().y())));
	ui.rz->setText((QString("%1").arg(focus->get_rotation().z())));
	//color
	ui.colorR->setText(QString("%1").arg(focus->get_color().x()));
	ui.colorG->setText(QString("%1").arg(focus->get_color().y()));
	ui.colorB->setText(QString("%1").arg(focus->get_color().z()));
	//metallic,roughness,ao
	ui.metallicSlider->setValue((int)(focus->get_metallic() * 100));
	ui.roughnessSlider->setValue((int)(focus->get_roughness() * 100));
	ui.aoSlider->setValue((int)(focus->get_ao() * 100));
	
}

void Property::set_render(Render* value)
{
	render = value;
}

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