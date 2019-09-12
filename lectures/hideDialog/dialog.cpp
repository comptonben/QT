#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QDialog *hd = new QDialog();
    hd->hide();

    connect(ui->inputLineEdit, &QLineEdit::textChanged, ui->outputLineEdit, &QLineEdit::setText);
    connect(ui->inputLineEdit, &QLineEdit::textChanged, ui->echoLabel, &QLabel::setText);
    connect(ui->clearButton, &QPushButton::clicked, ui->inputLineEdit, &QLineEdit::clear);
    connect(ui->quitButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->helpButton, &QPushButton::clicked, hd, &QDialog::show);
}

Dialog::~Dialog()
{
    delete ui;
}
