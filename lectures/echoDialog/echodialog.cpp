#include "echodialog.h"
#include "ui_echodialog.h"

EchoDialog::EchoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EchoDialog)
{
    ui->setupUi(this);

    connect(ui->inputLineEdit, &QLineEdit::textChanged, ui->outputLineEdit, &QLineEdit::setText);
    connect(ui->inputLineEdit, &QLineEdit::textChanged, ui->echoLabel, &QLabel::setText);
    connect(ui->clearButton, &QPushButton::clicked, ui->inputLineEdit, &QLineEdit::clear);
    connect(ui->quitButton, &QPushButton::clicked, this, &QDialog::accept);
}

EchoDialog::~EchoDialog()
{
    delete ui;
}
