#include "widget.h"
#include <QApplication>
#include <QDebug>

void flipBit(int b)
{
    qDebug() << "Bit = " << b;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QObject::connect(&w, &Widget::postBit, &flipBit);
    w.show();

    return a.exec();
}
