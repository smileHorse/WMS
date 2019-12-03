#include "MainFrame.h"
#include <QtWidgets/QApplication>
#include <QtCore/QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	// ������ʽ�ļ�
	QFile file(":/qss/MainFrame.qss");
	file.open(QFile::ReadOnly);
	QString strQss = file.readAll();
	a.setStyleSheet(strQss);

	MainFrame w;
	w.show();
	return a.exec();
}
