#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QLabel>
#include <QtDebug>
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

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QAction* red;
    QAction* blue;
    QAction* green;

private slots:
    void redCircle();
    void greenSquare();
    void bluePolygon();
};
#endif // MAINWINDOW_H
