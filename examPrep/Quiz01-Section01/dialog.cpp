#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->leftLabel->setNum(0);
    ui->rightLabel->setNum(5);
    ui->leftSlider->setValue(0);
    ui->rightSlider->setValue(5);

    /*
    // QT4
    connect(ui->leftSlider, SIGNAL(valueChanged(int)), ui->leftLabel, SLOT(setNum(int)));
    connect(ui->rightSlider, SIGNAL(valueChanged(int)), ui->rightLabel, SLOT(setNum(int)));

    connect(ui->leftSlider, SIGNAL(valueChanged(int)), this, SLOT(leftSliderChanged(int)));
    connect(ui->rightSlider, SIGNAL(valueChanged(int)), this, SLOT(rightSliderChanged(int)));
    */

    // QT5
    connect(ui->leftSlider, &QSlider::valueChanged, ui->leftLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(ui->rightSlider, &QSlider::valueChanged, ui->rightLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    connect(ui->leftSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged), this, &Dialog::leftSliderChanged);
    connect(ui->rightSlider, static_cast<void (QSlider::*)(int)>(&QSlider::valueChanged), this, &Dialog::rightSliderChanged);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::leftSliderChanged(int num)
{
    ui->rightSlider->setValue(5-num);
}

void Dialog::rightSliderChanged(int num)
{
    ui->leftSlider->setValue(5-num);
}


