#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QPushButton(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    illuminated = false;

    blackPixmap = new QPixmap(400, 100);
    blackPixmap->fill(Qt::black);
    painter = new QPainter(blackPixmap);
    blackIcon = new QIcon(*blackPixmap);
    delete painter;
    delete blackPixmap;

    redPixmap = new QPixmap(400, 100);
    redPixmap->fill(Qt::red);
    painter = new QPainter(redPixmap);
    redIcon = new QIcon(*redPixmap);
    delete painter;
    delete redPixmap;

    this->setIcon(*blackIcon);
    connect(this, &QPushButton::clicked, this, &Widget::togglePixmap);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *pe)
{
    if(illuminated)
        this->setIcon(*redIcon);
    else
        this->setIcon(*blackIcon);

    QPushButton::paintEvent(pe);
}

void Widget::togglePixmap()
{
    illuminated = !illuminated;

    this->update();
}
