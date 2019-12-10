#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QBrush>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTimer>

#include <stdlib.h>

#include "big_enemy.h"
#include "small_enemy.h"
#include "defs.h"
#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void spawnEnemy();
    void spawnBigEnemy();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    QSqlDatabase db;
    int randomNumber = 1000;
    int randmomNumber2 = 5000;

};

#endif // MAINWINDOW_H
