#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->verticalSlider, SIGNAL(valueChanged(int)),
            ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->verticalSlider, SLOT(setValue(int)));
}

Dialog::~Dialog()
{
    delete ui;
}
