#include "dialog.h"
#include "ui_dialog.h"
#include "memodialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->modalButton, &QPushButton::clicked,
            this, &Dialog::newModalDialog);
    connect(ui->nonModalButton, &QPushButton::clicked,
            this, &Dialog::newNonModalDialog);
    connect(ui->customButton, &QPushButton::clicked,
            this, &Dialog::newCustomDialog);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::newModalDialog()
{
    QDialog* d = new QDialog();
    QLabel* h = new QLabel("Hello");
    QLabel* w = new QLabel("World");
    QLabel* m = new QLabel("Modal");
    QVBoxLayout* layout = new QVBoxLayout;

    d->setLayout(layout);
    layout->addWidget(h);
    layout->addStretch();
    layout->addWidget(w);
    layout->addStretch();
    layout->addWidget(m);

    d->exec();
}

void Dialog::newNonModalDialog()
{
    QDialog* d = new QDialog();
    QLabel* h = new QLabel("Hello");
    QLabel* w = new QLabel("World");
    QLabel* n = new QLabel("Non-Modal");
    QVBoxLayout* layout = new QVBoxLayout;

    d->setLayout(layout);
    layout->addWidget(h);
    layout->addStretch();
    layout->addWidget(w);
    layout->addStretch();
    layout->addWidget(n);

    d->show();
}

void Dialog::newCustomDialog()
{
    MemoDialog* m = new MemoDialog;

    m->exec();
}
