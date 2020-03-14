#pragma once

#include <QWidget>
#include "ui_Property.h"
#include "RenderObject.h"

class Property : public QWidget
{
	Q_OBJECT

public:
	Property(QWidget *parent = Q_NULLPTR);
	~Property();
	void SetProperties();  //ѡ������������ʾ
	void set_render(Render* value);
	void SetConnection();  //������render����
	//slider��edit������
	void MetallicEditFromSlider(int value);
	void MetallicSliderFromEdit(const QString& text);
	void RoughnessEditFromSlider(int value);
	void RoughnessSliderFromEdit(const QString& text);
	void AOEditFromSlider(int value);
	void AOSliderFromEdit(const QString& text);
private:
	Ui::Property ui;
	Render* render;
};
