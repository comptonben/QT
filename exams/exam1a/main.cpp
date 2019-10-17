// *********************************
// DO NOT MODIFY OR SUBMIT THIS FILE
// *********************************

#include "dialog.h"
#include <QApplication>
#include <QtDebug>

void printStatus(bool status)
{
    if (status)
        qDebug() << "winnerStatus(true): winner";
    else
        qDebug() << "winnerStatus(false): loser";
}

void runTestHarness();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w;
    w.show();
    QObject::connect(&w, &Dialog::winnerStatus, &printStatus);

    if (argc > 1)
    {
        runTestHarness();
    }
    return a.exec();
}

void runTestHarness()
{
    /* TBD */
}
