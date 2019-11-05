#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap yourMap(400, 300);
    yourMap.fill(Qt::black);
    QPainter p(&yourMap);
    p.setRenderHint(QPainter::Antialiasing, true);

    p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::SolidPattern));
    QPoint points[4] = {QPoint(200, 100), QPoint(215, 175), QPoint(200, 150), QPoint(185, 175)};
    p.drawPolygon(points, 4);

    if(!yourMap.save("arrow.jpg"))
    {
        qDebug() << "Error - unable to save pixmap";
    }

    QPixmap myMap;
    if(!myMap.load("arrow.jpg", 0, Qt::AutoColor))
        qDebug() << "Error - unable to load pixmap";

    QLabel myLabel;
    myLabel.setPixmap(myMap);
    myLabel.show();
    return a.exec();
}

