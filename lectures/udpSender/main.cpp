#include "senderdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SenderDialog mysender;
    mysender.show();

    return a.exec();
}
