#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QPainter>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap myMap(400, 300);
    myMap.fill(Qt::black);
    QPainter p(&myMap);
    p.setRenderHint(QPainter::Antialiasing, true);

    p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::SolidPattern));
    QPoint points[4] = {QPoint(200, 100), QPoint(215, 175), QPoint(200, 150), QPoint(185, 175)};
    p.drawPolygon(points, 4);

    p.rotate(30);
    p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
    p.drawPolygon(points, 4);

    QLabel myLabel;
    myLabel.setPixmap(myMap);
    myLabel.show();
    return a.exec();
}
