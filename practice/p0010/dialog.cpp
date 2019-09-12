#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->resetButton, &QPushButton::clicked, this, &Dialog::reset);
    connect(ui->quitButton, &QPushButton::clicked, this, &QDialog::close);

    connect(ui->spinBox1, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Dialog::setSum);
    connect(ui->spinBox2, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &Dialog::setSum);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setSum()
{
    int a = ui->spinBox1->value() + ui->spinBox2->value();
    ui->sumLabel->setNum(a);
}

void Dialog::reset()
{
    ui->spinBox1->setValue(0);
    ui->spinBox2->setValue(0);
}
