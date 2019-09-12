#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->resetButton, SIGNAL(clicked()), SLOT(reset()));
    connect(ui->quitButton, SIGNAL(clicked()), SLOT(close()));

    connect(ui->spinBox1, SIGNAL(valueChanged(int)), SLOT(setSum()));
    connect(ui->spinBox2, SIGNAL(valueChanged(int)), SLOT(setSum()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setSum()
{
    int a = ui->spinBox1->value();
    int b = ui->spinBox2->value();
    a += b;
    ui->sumLabel->setNum(a);
}

void Dialog::reset()
{
    ui->spinBox1->setValue(0);
    ui->spinBox2->setValue(0);
}
