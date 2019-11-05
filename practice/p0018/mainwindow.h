#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include "mysocket.h"

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

    QAction* startAction;
    QAction* stopAction;
    QAction* clearAction;
    QAction* saveAction;
    QAction* quitAction;

    QMenu* fileMenu;
    QToolBar* toolBar;
    MySocket* aprs;
    QLabel* statusLabel;
    QString servername;
    QString username;
    quint16 port;

private slots:
    void applyConfiguration();
    void defaultConfiguration();
    void clearConfiguration();
    void startReceiving();
    void stopReceiving();
    void saveLog();
    void postStatus(QString);
    void postPacket(QByteArray);
};
#endif // MAINWINDOW_H
