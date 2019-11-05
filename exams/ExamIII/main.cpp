//
//  Do NOT modify this file
//

#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>

void testharness();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    testharness();

    return a.exec();
}

void testharness()
{
    /* Do NOT modify or delete */
}
