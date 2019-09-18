#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::keyPressEvent(QKeyEvent *ke)
{
    if(ke)
    {
        if(ke->key() == Qt::Key_Up)
        {
            ui->label->setText("Up");
        }

        else if(ke->key() == Qt::Key_Down)
        {
            ui->label->setText("Down");
        }

        else if(ke->key() == Qt::Key_Right)
        {
            ui->label->setText("Right");
        }

        else if(ke->key() == Qt::Key_Left)
        {
            ui->label->setText("Left");
        }
        QDialog::keyPressEvent(ke);
    }
    QDialog::keyPressEvent(ke);
}
