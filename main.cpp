#include "StewartPlatformSimulator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
	QApplication a(argc, argv);
	StewartPlatformSimulator w;
	w.show();
	return a.exec();
}
