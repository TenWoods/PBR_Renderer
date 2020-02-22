#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PBR_Renderer.h"

class PBR_Renderer : public QMainWindow
{
	Q_OBJECT

public:
	PBR_Renderer(QWidget *parent = Q_NULLPTR);

private:
	Ui::PBR_RendererClass ui;
};
