#include "StudyResourse.h"
#include <io.h>
#include <iostream>

StudyResourse::StudyResourse(QWidget *parent, int partIndex)
	: QDialog(parent), num_pointer(1), index(partIndex)
{
	ui.setupUi(this);
	QPixmap first(("LearnSource/part" + std::to_string(index) + "/1.png").c_str());
	ui.label->setPixmap(first);
	connect(ui.downButton, &QPushButton::clicked, this, &StudyResourse::NextPage);
	connect(ui.upButton, &QPushButton::clicked, this, &StudyResourse::LastPage);
}

StudyResourse::~StudyResourse()
{

}

//��һҳ��ť��Ӧ
void StudyResourse::NextPage()
{
	num_pointer += 1;
	if (num_pointer == amount)
	{
		ui.downButton->setText(QStringLiteral("���"));
	}
	if (num_pointer > amount)
	{
		reject();
		return;
	}
	QPixmap next(("LearnSource/part" + std::to_string(index) + "/" + std::to_string(num_pointer) + ".png").c_str());
	ui.label->setPixmap(next);
}

//��һҳ��ť��Ӧ
void StudyResourse::LastPage()
{
	if (num_pointer == amount)
	{
		ui.downButton->setText(QStringLiteral("��һҳ"));
	}
	num_pointer -= 1;
	if (num_pointer == 0)
	{
		num_pointer = 1;
	}
	QPixmap last(("LearnSource/part" + std::to_string(index) + "/" + std::to_string(num_pointer) + ".png").c_str());
	ui.label->setPixmap(last);
}