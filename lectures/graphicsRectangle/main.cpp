#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QBrush>
#include <QRect>
#include <QLabel>
#include <QDialog>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    QApplication myApp(argc, argv);
    QPixmap myMap(400, 300);
    QPainter p(&myMap);
    p.setRenderHint(QPainter::Antialiasing, true);

    // Draw frame just within perimeter
    p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::SquareCap));
    p.drawRect(10, 10, 380, 280);

    // Vary Cap Style
    p.setPen(QPen(Qt::blue, 10, Qt::SolidLine, Qt::SquareCap));
    QRect rect1(25, 25, 50, 30);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    // Vary Join Style
    p.setPen(QPen(Qt::blue, 10, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    rect1.translate(-200, 75);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::FlatCap, Qt::RoundJoin));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    // Vary Line Style
    p.setPen(QPen(Qt::blue, 2, Qt::DashLine, Qt::SquareCap));
    rect1.translate(-200, 75);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 2, Qt::DotLine, Qt::RoundCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::green, 2, Qt::DashDotDotLine, Qt::FlatCap));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    // Vary Brush Style
    p.setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::SquareCap));
    p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    rect1.translate(-200, 75);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap));
    p.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    p.setPen(QPen(Qt::green, 2, Qt::DashDotDotLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::green, Qt::VerPattern));
    rect1.translate(100, 0);
    p.drawRect(rect1);

    QLabel myLabel;
    myLabel.setPixmap(myMap);
    myLabel.show();

    return myApp.exec();
}
