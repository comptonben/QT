#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QKeyEvent>
#include <QTimer>
#include <QLabel>
#include <QBrush>
#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QVector>
#include "pellet.h"
#include "cat.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addScore();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QGraphicsScene* scene;

    QTimer* timer;

    Cat* cat;
    QVector<QPixmap*> catpixs;
    QPixmap* pix;
    QGraphicsRectItem* walls;
    Pellet* temp_pellet;
    QVector<Pellet*> pellets;

    QLabel* score;
    int points;


protected:
    void keyPressEvent(QKeyEvent*);
    bool eventFilter(QObject* obj, QEvent *event);

};

#endif // MAINWINDOW_H
