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

    // Draw four points and two crosshair lines
    p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap));
    QPoint p1(200, 25);
    QPoint p2(200, 275);
    QPoint p3(50, 150);
    QPoint p4(350, 150);
    p.drawPoint(p1);
    p.drawPoint(p2);
    p.drawPoint(p3);
    p.drawPoint(p4);
    p.setPen(QPen(Qt::white, 5, Qt::SolidLine, Qt::FlatCap));
    QLine line1(p1, p2);
    QLine line2(p3, p4);
    p.drawLine(line1);
    p.drawLine(line2);

    // Define Bounding Rectangle, set pen, draq ellipse
    p.setPen(QPen(Qt::blue, 5, Qt::SolidLine, Qt::SquareCap));
    QRect rect1(125, 75, 150, 150);
    p.drawEllipse(rect1);

    // Write text
    p.setPen(Qt::red);
    QPoint tp(300, 175);
    p.drawText(tp, "Fire");

    // Draw Arcs --- andles are 1/16 of a degree, hence the scale factor
    p.setPen(Qt::green);
    p.drawArc(QRect(100, 50, 200, 200), 00*16, 90*16);
    p.drawArc(QRect(100, 50, 200, 200), 180*16, 90*16);
    p.drawArc(QRect(100, 50, 200, 200), 120*16, 30*16);
    p.drawArc(QRect(100, 50, 200, 200), 300*16, 30*16);

    QLabel myLabel;
    myLabel.setPixmap(myMap);
    myLabel.show();

    return myApp.exec();
}
