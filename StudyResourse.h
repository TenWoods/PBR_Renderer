#pragma once

#include <QDialog>
#include "ui_StudyResourse.h"

class StudyResourse : public QDialog
{
	Q_OBJECT

public:
	StudyResourse(QWidget *parent = Q_NULLPTR);
	~StudyResourse();

private:
	Ui::StudyResourse ui;
};
