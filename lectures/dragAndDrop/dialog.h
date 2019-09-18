#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "draglabel.h"
#include "droplabel.h"

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

    DropLabel* d1;
    DropLabel* d2;
    DropLabel* d3;
    DropLabel* d4;

    DragLabel* s1;
    DragLabel* s2;
    DragLabel* s3;
    DragLabel* s4;

    QLabel* d0;
    QLabel* s0;
};

#endif // DIALOG_H
