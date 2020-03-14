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
	void SetProperties();  //选中物体属性显示
	void set_render(Render* value);
	void SetConnection();  //设置与render连接
	//slider与edit的联动
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
