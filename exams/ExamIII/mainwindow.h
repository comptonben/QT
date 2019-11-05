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
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;   // This variable must remain PUBLIC

private:
    QTcpSocket *socket;

    QTimer* clock;
    QGraphicsScene* scene;
    QGraphicsRectItem* sec;
    QGraphicsRectItem* min;
    QGraphicsRectItem* hour;

    QLabel* statusLabel;

private slots:
    void updateStatus(QString& s);
    void processPendingDatagrams();
    void clockMove();
    void clockStart();
    void clockSpeed();

};

#endif // MAINWINDOW_H
