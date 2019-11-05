#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtDebug>
#include <QHostAddress>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QFont>
#include <QTimer>
#include <QDialog>

// Orbit Radius
const int redOrbit = 85;
const int greenOrbit = 100;
const int blueOrbit = 125;

// Planet Diameter
const int sunD = 40;
const int redD = 10;
const int greenD = 20;
const int blueD = 30;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTcpSocket *myTCP;

    QGraphicsEllipseItem *redPlanet;
    QGraphicsEllipseItem *greenPlanet;
    QGraphicsEllipseItem *bluePlanet;

    QTimer *timer;


private slots:
    void processPendingDatagrams();
    void planetMove();
    void startButton();
    void planetSpeed();

};

#endif // MAINWINDOW_H
