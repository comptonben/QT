#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QToolBar>

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

    QLabel* status;
    QAction* action1;
    QAction* action2;
    QAction* action3;
    QMenu* actionMenu;
    QToolBar* toolBar;

private slots:
    void clearNumber();
    void dialNumber();
    void defaultAreaCode();
    void defaultPrefix();
    void defaultSubscriber();
};

#endif // MAINWINDOW_H
