#include "dialog.h"
#include "ui_dialog.h"

#include <QTimer>
#include <QtDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->timerLabel->setText("0");
    updateTimer = QObject::startTimer(1000);
    paused = true;

    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(initiateTimer()));
    connect(ui->pauseButton, SIGNAL(clicked()), this, SLOT(pauseTimer()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearTimer()));

    QTimerEvent* event = new QTimerEvent(updateTimer);

    QCoreApplication::postEvent(this, event);
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::event(QEvent* someEvent)
{
    if(!someEvent) return QObject::event(someEvent);
    if(someEvent->type() == QEvent::Timer)
    {
        QTimerEvent* timerEvent = static_cast<QTimerEvent*>(someEvent);
        if(timerEvent->timerId() == updateTimer)
        {
            if (!paused)
            {
                bool ok;
                int n = ui->timerLabel->text().toInt(&ok) + 1;
                if (ok)
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
            else qDebug() << "Timer paused";
        }
    }
    return QObject::event(someEvent);
}

void Dialog::initiateTimer()
{
    qDebug() << "Initiating timer";
    paused = false;
}

void Dialog::pauseTimer()
{
    qDebug() << "Pausing timer";
    paused = true;
}

void Dialog::clearTimer()
{
    qDebug() << "Clearing timer";
    ui->timerLabel->setText("0");
    paused = true;
}
