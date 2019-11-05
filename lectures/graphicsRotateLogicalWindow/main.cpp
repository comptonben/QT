#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QPoint>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap myMap(400, 300);
    myMap.fill(Qt::black);
    QPainter p(&myMap);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setWindow(-50, -50, 100, 100);

    p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::SolidPattern));
    QPoint points[4] = {QPoint(0, 25), QPoint(15, -25), QPoint(0, 0), QPoint(-15, -25)};
    p.drawPolygon(points, 4);

    p.rotate(45);
    p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
    p.drawPolygon(points, 4);

    QLabel myLabel;
    myLabel.setPixmap(myMap);
    myLabel.show();
    return a.exec();
}
