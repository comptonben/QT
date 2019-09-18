#include "dialog.h"
#include "ui_dialog.h"

#include <QIntValidator>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QIntValidator* intVal = new QIntValidator(ui->lineEdit);
    ui->lineEdit->setValidator(intVal);

    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(ui->lineEdit, &QLineEdit::textChanged, ui->convertLabel, &QLabel::clear);
    connect(ui->binaryButton, &QPushButton::clicked, this, &Dialog::binary);
    connect(ui->octalButton, &QPushButton::clicked, this, &Dialog::octal);
    connect(ui->hexButton, &QPushButton::clicked, this, &Dialog::hex);
    connect(ui->clearButton, &QPushButton::clicked, this, &Dialog::clear);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::binary()
{
    auto temp = ui->lineEdit->text();
    if(!temp.isEmpty())
        ui->convertLabel->setText(temp.number(temp.toInt(), 2));
}

void Dialog::octal()
{
    auto temp = ui->lineEdit->text();
    if(!temp.isEmpty())
        ui->convertLabel->setText(temp.number(temp.toInt(), 8));
}

void Dialog::hex()
{
    auto temp = ui->lineEdit->text();
    if(!temp.isEmpty())
        ui->convertLabel->setText(temp.number(temp.toInt(), 16));
}

void Dialog::clear()
{
    ui->lineEdit->clear();
    ui->convertLabel->clear();
}
