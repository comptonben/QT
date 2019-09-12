#include "echodialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EchoDialog w;
    w.show();

    return a.exec();
}
