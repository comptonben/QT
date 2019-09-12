#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QT4 style
    connect(ui->toolButton1, SIGNAL(clicked(bool)), this, SLOT(tbutton()));
    connect(ui->toolButton2, SIGNAL(clicked(bool)), this, SLOT(tbutton()));
    connect(ui->toolButton3, SIGNAL(clicked(bool)), this, SLOT(tbutton()));
    connect(ui->toolButton4, SIGNAL(clicked(bool)), this, SLOT(tbutton()));

    connect(ui->goButton, SIGNAL(clicked(bool)), this, SLOT(gbutton()));
    connect(ui->pauseButton, SIGNAL(clicked(bool)), this, SLOT(pbutton()));
    connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(sbutton()));

    // QT5 style
    connect(ui->clearButton, &QPushButton::clicked, ui->lineEdit, &QLineEdit::clear);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Widget::writeMsg);

    // connect with custom slot
    connect(ui->bitButton, &QRadioButton::clicked, this, &Widget::sendCustomSignal);

    // connect with overloaded slot function
    connect(this, &Widget::postBit, ui->label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendCustomSignal()
{
    if(ui->bitButton->isChecked())
        emit postBit(1);
    else
        emit postBit(0);
}

void Widget::tbutton()
{
    writeMsg("Tool Button");
}

void Widget::gbutton()
{
    writeMsg("Go");
}

void Widget::pbutton()
{
    writeMsg("Pause");
}

void Widget::sbutton()
{
    writeMsg("Stop");
}

void Widget::writeMsg(QString s)
{
    qDebug() << s;
}
