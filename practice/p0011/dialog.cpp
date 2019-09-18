#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->quitButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->dial, &QDial::valueChanged, ui->volumeLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}

Dialog::~Dialog()
{
    delete ui;
}

