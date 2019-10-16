#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <QPoint>
#include <QLine>
#include <QFont>
#include <QLabel>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    QApplication myApp(argc, argv);
    QPixmap myMap(400, 300);
    myMap.fill(Qt::black);
    QPainter p(&myMap);
    p.setRenderHint(QPainter::Antialiasing, true);

    // Draw red arrow polygon
    p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::SolidPattern));
    QPoint points[4] = {QPoint(200,100), QPoint(215,175), QPoint(200,150), QPoint(185,175)};
    p.drawPolygon(points, 4);

    // Apply translation and redraw as green polygon
    p.translate(75, 50);
    p.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
    p.drawPolygon(points, 4);

    QLabel myLabel;
    myLabel.setPixmap(myMap);
    myLabel.show();
    return myApp.exec();
}
