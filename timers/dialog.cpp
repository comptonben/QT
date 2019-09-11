#include "dialog.h"
#include "ui_dialog.h"

#include <QTimer>
#include <QtDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->quit, SIGNAL(clicked()), this, SLOT(accept()));
    ui->timerLabel->setText("0");
    timer = new QTimer(this);

    timer->setInterval(1000);
    paused = true;

    connect(ui->start, SIGNAL(clicked()), this, SLOT(initiateTimer()));
    connect(ui->pause, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clearTimer()));

    connect(timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initiateTimer()
{
    qDebug() << "Initiating Timer";
    paused = false;
    timer->start();
}

void Dialog::pauseTimer()
{
    qDebug() << "Pausing Timer";
    paused = true;
    timer->stop();
}

void Dialog::clearTimer()
{
    qDebug() << "Clearing Timer";
    ui->timerLabel->setText("0");
    paused = true;
    timer->stop();
}

void Dialog::updateDisplay()
{
    if (!paused)
    {
        bool ok;
        int n = ui->timerLabel->text().toInt(&ok) + 1;
        if(ok)
        {
            ui->timerLabel->setText(QString::number(n));
            qDebug() << "Updating display";
        }
        else
        {
            ui->timerLabel->setText("");
            qDebug() << "Dialog::eventTimer(): Unknown error";
        }
    }
    else
    {
        qDebug() << "Timer paused";
    }
}
