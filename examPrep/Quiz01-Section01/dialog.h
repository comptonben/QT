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

    Ui::Dialog *ui;  /* The UI variable must remain a PUBLIC variable or you will receive ZERO credit! */
private slots:
    void leftSliderChanged(int num);
    void rightSliderChanged(int num);

};

#endif // DIALOG_H
