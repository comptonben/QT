#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QFile>
#include <QtDebug>
#include <QMouseEvent>
#include <QIntValidator>
#include <QDialog>
#include <QHBoxLayout>

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
    void mousePressEvent(QMouseEvent *me);
    bool eventFilter(QObject *obj, QEvent *e);

private:
    Ui::MainWindow *ui;
    QAction *action;
    QLabel *status;
    int count = 0;
    QDialog *dialog;
    QDialog dialogArr[99];

private slots:
    void loadFile();
    void actionTriggered();
    void spawnButton();
};

#endif // MAINWINDOW_H
