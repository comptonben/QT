#include "form.h"
#include "ui_form.h"
#include <stdlib.h>

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->spinButton, SIGNAL(clicked()), this, SLOT(processSpin()));
}

Form::~Form()
{
    delete ui;
}

void Form::processSpin()
{
    int one = qrand() % MODULUS;
    int two = qrand() % MODULUS;
    int three = qrand() % MODULUS;

    ui->dial1->setText(QString::number(one));
    ui->dial2->setText(QString::number(two));
    ui->dial3->setText(QString::number(three));

    int spins = ui->spins->text().toInt() + 1;
    ui->spins->setText(QString::number(spins));

    if ((one == two) && (two == three))
    {
        emit updateStatus(QString("Status: Winner!!"));
        int wins = ui->wins->text().toInt() + 1;
        ui->wins->setText(QString::number(wins));
    }
    else
    {
        emit updateStatus(QString("Status: Loser!!"));
    }
}
