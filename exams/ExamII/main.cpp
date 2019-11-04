#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>

void testHarness();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    testHarness();
    return a.exec();
}

void testHarness()
{
    /* TBD */
}
