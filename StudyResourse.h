#pragma once

#include <QDialog>
#include "ui_StudyResourse.h"

class StudyResourse : public QDialog
{
	Q_OBJECT

public:
	StudyResourse(QWidget *parent = Q_NULLPTR, int partIndex = 1);
	~StudyResourse();
public slots:
	void NextPage();
	void LastPage();

private:
	Ui::StudyResourse ui;
	int amount;
	int num_pointer;
	int index;
};
