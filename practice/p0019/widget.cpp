#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myUdpSocket = new QUdpSocket(this);
    myUdpSocket->bind(QHostAddress::AnyIPv4, 8888, QUdpSocket::ShareAddress);
    connect(myUdpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagram()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processPendingDatagram()
{
    QByteArray datagram;

    while(myUdpSocket->hasPendingDatagrams())
    {
        datagram.resize(myUdpSocket->pendingDatagramSize());
        myUdpSocket->readDatagram(datagram.data(), datagram.size());
        datagram.chop(2);
        ui->textBrowser->append(QString(datagram));
    }
}
