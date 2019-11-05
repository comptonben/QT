#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QLabel>
#include <QColor>

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

    QAction* loadImage;
    QAction* saveImage;
    QAction* quit;
    QMenu* menu;

    QLabel* statusLabel;

    QColor foregroundColor;
    QColor backgroundColor;

private slots:
    void loadLabelImage();
    void saveLabelImage();
    void newLabelImage();
    void backgroundChanged();
    void foregroundChanged();
};
#endif // MAINWINDOW_H
