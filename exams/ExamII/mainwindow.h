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
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegularExpressionValidator>
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
    bool eventFilter(QObject *obj, QEvent *e);

private:
    Ui::MainWindow *ui;
    QLabel *status;
    int lineCount = 1;

private slots:
    void loadFile();
    void saveFile();
    void spawnButton();
    void applyButton();

};

#endif // MAINWINDOW_H
