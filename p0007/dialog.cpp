#include "dialog.h"
#include "ui_dialog.h"

#include <QSlider>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->verticalSlider, &QSlider::valueChanged,
            ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged,
            ui->verticalSlider, &QSlider::setValue);
}

Dialog::~Dialog()
{
    delete ui;
}
