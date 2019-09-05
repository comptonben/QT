// pushtoquit.cpp -- Pushbutton example
#include <QtDebug>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
static void PrintStuff()
{
	qDebug() << "HelloWorld"; // outputs to console
}

int main(int argc, char* argv[])
{
	QApplication myApp(argc, argv);

	QPushButton pushbutton("Push to Quit");
	QLabel label(0);
	QSlider slider(0);

	QObject::connect(&pushbutton,		// source address
			&QPushButton::clicked,
			&myApp,			// destination address
			&QApplication::quit);
	QObject::connect(&pushbutton, &QPushButton::clicked,
			&PrintStuff);
	QObject::connect(&slider, &QSlider::valueChanged, &label,
			static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

	pushbutton.show();
	slider.show();
	label.show();
	return myApp.exec();
}
