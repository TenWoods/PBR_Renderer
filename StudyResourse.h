#pragma once

#include <QDialog>
#include "ui_StudyResourse.h"

class PBR_Renderer;

class StudyResourse : public QDialog
{
	Q_OBJECT

public:
	StudyResourse(QWidget *parent = Q_NULLPTR, int partIndex = 1, PBR_Renderer* father = NULL);
	~StudyResourse();
public slots:
	void NextPage();
	void LastPage();

protected:

	virtual void resizeEvent(QResizeEvent* event) override;

private:
	Ui::StudyResourse ui;
	int amount;
	int num_pointer;
	int index;
	PBR_Renderer* m_father;
};
