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

public slots:
    void leftDialChanged(int num);
    void rightDialChanged(int num);

};

#endif // DIALOG_H
