#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->rightDial->setValue(5);
    ui->leftDial->setValue(0);
    ui->rightLabel->setNum(5);
    ui->leftLabel->setNum(0);

    connect(ui->rightDial, &QDial::valueChanged, ui->rightLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(ui->leftDial, &QDial::valueChanged, ui->leftLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    connect(ui->leftDial, static_cast<void (QDial::*)(int)>(&QDial::valueChanged), this, &Dialog::leftDialChanged);
    connect(ui->rightDial, static_cast<void (QDial::*)(int)>(&QDial::valueChanged), this, &Dialog::rightDialChanged);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::leftDialChanged(int num)
{
    ui->rightDial->setValue(5-num);
}

void Dialog::rightDialChanged(int num)
{
    ui->leftDial->setValue(5-num);
}


