#include "dialog.h"
#include "ui_dialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QVBoxLayout* rLayout = new QVBoxLayout;
    QVBoxLayout* cLayout = new QVBoxLayout;
    QVBoxLayout* lLayout = new QVBoxLayout;


    mainLayout->addStretch();
    mainLayout->addLayout(rLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(cLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(lLayout);
    mainLayout->addStretch();

    r1 = new DaDLabel(":/images/Picture1.png");
    r2 = new DaDLabel(":/images/Picture1.png");
    r3 = new DaDLabel(":/images/Picture1.png");

    rLayout->addStretch();
    rLayout->addWidget(r1);
    rLayout->addWidget(r2);
    rLayout->addWidget(r3);
    rLayout->addStretch();

    c1 = new DaDLabel(":/images/Picture2.png");
    c2 = new DaDLabel(":/images/Picture2.png");
    c3 = new DaDLabel(":/images/Picture2.png");

    cLayout->addStretch();
    cLayout->addWidget(c1);
    cLayout->addWidget(c2);
    cLayout->addWidget(c3);
    cLayout->addStretch();

    l1 = new DaDLabel(":/images/Picture3.png");
    l2 = new DaDLabel(":/images/Picture3.png");
    l3 = new DaDLabel(":/images/Picture3.png");

    lLayout->addStretch();
    lLayout->addWidget(l1);
    lLayout->addWidget(l2);
    lLayout->addWidget(l3);
    lLayout->addStretch();
}

Dialog::~Dialog()
{
    delete ui;
}
