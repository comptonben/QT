#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    bool event(QEvent * e);

protected:
    void keyPressEvent(QKeyEvent * ke);

private:
    Ui::MainWindow *ui;
    QLabel* status;

private slots:
    void loadFile();
};

#endif // MAINWINDOW_H
