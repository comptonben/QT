#include "dialog.h"
#include "ui_dialog.h"
#include <QIntValidator>
#include "beepintvalidator.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    BeepIntValidator *beepDefault = new BeepIntValidator(ui->beepDefault);
    ui->beepDefault->setValidator(beepDefault);

    BeepIntValidator *beepRange = new BeepIntValidator(0, 255, ui->beepRange);
    ui->beepRange->setValidator(beepRange);

    QIntValidator *intRange = new QIntValidator(0, 255, ui->intRange);
    ui->intRange->setValidator(intRange);
}

Dialog::~Dialog()
{
    delete ui;
}
