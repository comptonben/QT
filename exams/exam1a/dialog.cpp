#include "dialog.h"
#include "ui_dialog.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialog>
#include <QtDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->mysteryButton->setText("bc0045");
    ui->toggleButton->setText("Disable");

    connect(ui->mysteryButton, &QPushButton::clicked, this, &Dialog::mysteryButton);
    connect(ui->toggleButton, &QPushButton::clicked, this, &Dialog::toggleButton);

    ui->rowLabel->setNum(1);
    ui->columnLabel->setNum(1);

    connect(ui->rowDial, SIGNAL(valueChanged(int)), ui->rowLabel, SLOT(setNum(int)));
    connect(ui->columnDial, SIGNAL(valueChanged(int)), ui->columnLabel, SLOT(setNum(int)));
    connect(ui->spawnButton, &QPushButton::clicked, this, &Dialog::spawnButton);

    connect(ui->winnerButton, &QPushButton::clicked, this, &Dialog::winnerButton);
    connect(ui->resetButton, &QPushButton::clicked, this, &Dialog::resetButton);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mysteryButton()
{
    auto temp = ui->lineEdit->text();
    if(temp == "")
        ui->mysteryButton->setText("BLANK");
    else
        ui->mysteryButton->setText(temp);
    ui->lineEdit->clear();
}

void Dialog::toggleButton()
{
    bool flag;
    if(ui->toggleButton->text() == "Disable")
    {
        ui->toggleButton->setText("Enable");
        flag = true;
    }
    else
    {
        ui->toggleButton->setText("Disable");
        flag = false;
    }
    ui->lineEdit->setReadOnly(flag);
}

void Dialog::spawnButton()
{
    QDialog *dialog = new QDialog();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QGridLayout *grid = new QGridLayout();
    QPushButton *closeButton = new QPushButton("Close");

    auto i = ui->rowDial->value();
    auto j = ui->columnDial->value();

    for(int n=0; n<i; n++)
    {
        for(int m=0; m<j; m++)
        {
            QLabel *label = new QLabel();
            label->setNum(n);
            label->setFrameShape(QLabel::WinPanel);
            grid->addWidget(label, n, m);
        }
    }

    dialog->setLayout(mainLayout);
    mainLayout->addLayout(grid);
    mainLayout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->exec();
}

void Dialog::winnerButton()
{
    bool flag;
    if(ui->button1->isChecked() && ui->button2->isChecked() && ui->button3->isChecked())
        flag = true;
    else if(ui->button4->isChecked() && ui->button5->isChecked() && ui->button6->isChecked())
        flag = true;
    else if(ui->button7->isChecked() && ui->button8->isChecked() && ui->button9->isChecked())
        flag = true;
    else if(ui->button1->isChecked() && ui->button4->isChecked() && ui->button7->isChecked())
        flag = true;
    else if(ui->button2->isChecked() && ui->button5->isChecked() && ui->button8->isChecked())
        flag = true;
    else if(ui->button3->isChecked() && ui->button6->isChecked() && ui->button9->isChecked())
        flag = true;
    else if(ui->button1->isChecked() && ui->button5->isChecked() && ui->button9->isChecked())
        flag = true;
    else if(ui->button3->isChecked() && ui->button5->isChecked() && ui->button7->isChecked())
        flag = true;
    else {
        flag = false;
    }
    emit winnerStatus(flag);
}

void Dialog::resetButton()
{
    ui->button1->setChecked(false);
    ui->button2->setChecked(false);
    ui->button3->setChecked(false);
    ui->button4->setChecked(false);
    ui->button5->setChecked(false);
    ui->button6->setChecked(false);
    ui->button7->setChecked(false);
    ui->button8->setChecked(false);
    ui->button9->setChecked(false);
}
