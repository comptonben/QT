#include "dialog.h"
#include "ui_dialog.h"

#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QDoubleValidator>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QIntValidator *intN = new QIntValidator(ui->intLineEdit);
    ui->intLineEdit->setValidator(intN);

    QIntValidator *intR = new QIntValidator(0, 255, ui->intRLineEdit);
    ui->intRLineEdit->setValidator(intR);

    QRegularExpressionValidator *binByte = new QRegularExpressionValidator(QRegularExpression("[0-1]{1,8}"), ui->binaryLineEdit);
    ui->binaryLineEdit->setValidator(binByte);

    QRegularExpressionValidator *hexByte = new QRegularExpressionValidator(QRegularExpression("[0-9A-Fa-f]{1,2}"), ui->hexLineEdit);
    ui->hexLineEdit->setValidator(hexByte);

    QDoubleValidator *floatReg = new QDoubleValidator(-100.0, 100.0, 1, ui->floatLineEdit);
    ui->floatLineEdit->setValidator(floatReg);

    QRegularExpressionValidator *lower = new QRegularExpressionValidator(QRegularExpression("[a-z]{1,15}"), ui->lowerLineEdit);
    ui->lowerLineEdit->setValidator(lower);

    QRegularExpressionValidator *upLow = new QRegularExpressionValidator(QRegularExpression("[A-Za-z]{1,15}"), ui->upOrLowLineEdit);
    ui->upOrLowLineEdit->setValidator(upLow);

    QRegularExpressionValidator *phone = new QRegularExpressionValidator(QRegularExpression("[0-9]{3}-[0-9]{3}-[0-9]{4}"), ui->phoneLineEdit);
    ui->phoneLineEdit->setValidator(phone);
}

Dialog::~Dialog()
{
    delete ui;
}
