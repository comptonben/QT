#include "udplabel.h"
#include "ui_udplabel.h"

UDPLabel::UDPLabel(QString msg) :
    QLabel(msg),
    ui(new Ui::UDPLabel)
{
    ui->setupUi(this);

    myUDPSocket = new QUdpSocket(this);
    myUDPSocket->bind(5876);

    connect(myUDPSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));

    // QT5
    // connect(myUDPSocket, &QUdpSocket::readyRead, this, &UDPLabel::processPendingDatagrams);
}

UDPLabel::~UDPLabel()
{
    delete ui;
}

void UDPLabel::processPendingDatagrams()
{
    QByteArray mydatagram;

    while(myUDPSocket->hasPendingDatagrams())
    {
        mydatagram.resize(myUDPSocket->pendingDatagramSize());
        myUDPSocket->readDatagram(mydatagram.data(), mydatagram.size());
    }

    QString msg;
    QTextStream in(&mydatagram, QIODevice::ReadOnly);

    in >> msg;
    this->setText(msg);
}
