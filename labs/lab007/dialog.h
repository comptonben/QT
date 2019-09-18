#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "dadlabel.h"

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

    DaDLabel* r1;
    DaDLabel* r2;
    DaDLabel* r3;

    DaDLabel* c1;
    DaDLabel* c2;
    DaDLabel* c3;

    DaDLabel* l1;
    DaDLabel* l2;
    DaDLabel* l3;
};

#endif // DIALOG_H
