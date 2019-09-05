// hlayout.cpp -- Horizontal layout example
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);

	QWidget widget;
	QHBoxLayout mainLayout;

	widget.setLayout(&mainLayout);

	QLabel label1("A");
	QLabel label2("B");
	QLabel label3("C");

	mainLayout.addWidget(&label1);
	mainLayout.addWidget(&label2);
	mainLayout.addWidget(&label3);

	widget.show();
	return myApp.exec();
}
