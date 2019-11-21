#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "defs.h"
#include "target.h"


#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QtDebug>
#include <QMouseEvent>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer* delay;
    // Target* target

    QSqlDatabase db;

private slots:
    void startCycle();
    void createTarget();
    void showStatistics();
    void purgeDatabase();

public slots:
    void resetCycle();
};

#endif // MAINWINDOW_H
