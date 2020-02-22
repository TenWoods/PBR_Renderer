#include "PBR_Renderer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PBR_Renderer w;
	w.show();
	return a.exec();
}
