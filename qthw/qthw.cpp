// Qt Hello World program - qthw.cpp
#include <QApplication>
#include <QLabel>
int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);
	QLabel label("Qt Hello World");
	label.show();
	return myApp.exec();
}
