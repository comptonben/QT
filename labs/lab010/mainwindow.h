#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "graphicsrectitem.h"
#include "alien.h"
#include "defs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *ke);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    GraphicsRectItem *rect1;
    QGraphicsRectItem *target;
};
#endif // MAINWINDOW_H
