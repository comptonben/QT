#include "dialog.h"
#include "ui_dialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* dLayout = new QHBoxLayout;
    QHBoxLayout* sLayout = new QHBoxLayout;

    mainLayout->addLayout(dLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(sLayout);

    d0 = new QLabel("Drop Here");
    d1 = new DropLabel;
    d2 = new DropLabel;
    d3 = new DropLabel;
    d4 = new DropLabel;

    dLayout->addWidget(d0);
    dLayout->addWidget(d1);
    dLayout->addWidget(d2);
    dLayout->addWidget(d3);
    dLayout->addWidget(d4);

    s0 = new QLabel("Drag Me");
    s1 = new DragLabel(":/images/Picture1.png");
    s2 = new DragLabel(":/images/Picture2.png");
    s3 = new DragLabel(":/images/Picture3.png");
    s4 = new DragLabel(":/images/Picture4.png");

    sLayout->addWidget(s0);
    sLayout->addWidget(s1);
    sLayout->addWidget(s2);
    sLayout->addWidget(s3);
    sLayout->addWidget(s4);
}

Dialog::~Dialog()
{
    delete ui;
}
