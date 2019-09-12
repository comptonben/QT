#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int updateTimer;
    bool paused;
    QTimer* timer;

private slots:
    void initiateTimer();
    void pauseTimer();
    void clearTimer();
    void updateDisplay();
};

#endif // DIALOG_H
