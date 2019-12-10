#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

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

    QGraphicsScene* scene;
    QSqlDatabase database;
    qreal x[10];
    qreal y[10];
    qreal dx[10];
    qreal dy[10];

    bool ok = true;
};

#endif // MAINWINDOW_H
