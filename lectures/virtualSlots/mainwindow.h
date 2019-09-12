#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QLabel>
#include "form.h"

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
    Form *form;

    QAction* helpAction;
    QAction* aboutQtAction;
    QAction* quitAction;

    QMenu* optionsMenu;
    QToolBar* toolBar;
    QLabel* statusLabel;
private slots:
    void showHelp();

};

#endif // MAINWINDOW_H
