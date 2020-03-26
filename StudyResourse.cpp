#include "StudyResourse.h"
#include "PBR_Renderer.h"
#include <io.h>
#include <iostream>

StudyResourse::StudyResourse(QWidget *parent, int partIndex, PBR_Renderer* father)
	: QDialog(parent), num_pointer(1), index(partIndex), m_father(father)
{
	ui.setupUi(this);
	amount = 0;
	QDir path(("LearnSource/part" + std::to_string(index)).c_str());
	path.setFilter(QDir::Files);
	QFileInfoList list = path.entryInfoList();
	QFileInfo fileInfo;
	foreach(fileInfo, list)
	{
		amount += 1;
	}
	std::cout << amount;
	QPixmap first(("LearnSource/part" + std::to_string(index) + "/1.png").c_str());
	ui.label->setPixmap(first);
	ui.label->setScaledContents(true);
	ui.label->resize(ui.widget->size());
	connect(ui.downButton, &QPushButton::clicked, this, &StudyResourse::NextPage);
	connect(ui.upButton, &QPushButton::clicked, this, &StudyResourse::LastPage);
}

StudyResourse::~StudyResourse()
{

}

void StudyResourse::resizeEvent(QResizeEvent* event)
{
	ui.label->resize(ui.widget_2->size());
}

//下一页按钮响应
void StudyResourse::NextPage()
{
	num_pointer += 1;
	if (num_pointer == amount)
	{
		ui.downButton->setText(QStringLiteral("完成"));
		connect(ui.downButton, &QPushButton::clicked, m_father, &PBR_Renderer::UnlockMaterial);
	}
	if (num_pointer > amount)
	{
		reject();
		return;
	}
	QPixmap next(("LearnSource/part" + std::to_string(index) + "/" + std::to_string(num_pointer) + ".png").c_str());
	ui.label->setPixmap(next);
}

//上一页按钮响应
void StudyResourse::LastPage()
{
	if (num_pointer == amount)
	{
		ui.downButton->setText(QStringLiteral("下一页"));
		disconnect();
	}
	num_pointer -= 1;
	if (num_pointer == 0)
	{
		num_pointer = 1;
	}
	QPixmap last(("LearnSource/part" + std::to_string(index) + "/" + std::to_string(num_pointer) + ".png").c_str());
	ui.label->setPixmap(last);
}