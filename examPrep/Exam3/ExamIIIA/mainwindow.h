#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBrush>
#include <QPen>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QDialog>
#include "label.h"
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //P01
    QTcpSocket* socket;

    //P02

    //P03
    QTimer* clock;
    QGraphicsScene* scene;
    QGraphicsRectItem* sec;
    QGraphicsRectItem* min;
    QGraphicsRectItem* hour;

private slots:
    //P01
    void loadImage();

    //P02
    void makeLabels();

    //P03
    void clockTick();
    void clockStartStop();
    void clockSpeed(int);
};

#endif // MAINWINDOW_H
