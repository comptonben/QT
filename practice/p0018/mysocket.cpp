#include "mysocket.h"
#include <QByteArray>
#include <QtDebug>

MySocket::MySocket()
{
    connect(this, &QTcpSocket::readyRead, this, &MySocket::processMessage);
    connect(this, &QTcpSocket::connected, this, &MySocket::sendConnected);
    connect(this, &QTcpSocket::disconnected, this, &MySocket::sendDisconnected);
}

void MySocket::connectToARPSServer(const QString &hostName, quint16 port)
{
    QString status;

    this->connectToHost(hostName, port, QIODevice::ReadWrite);

    if(!this->isValid())
    {
        status = "Error: unable to connect";
        emit sendStatus(status);
    }
}

void MySocket::sendAuthentication(const QString &userName)
{
    QString status;

    if(this->isValid())
    {
        QByteArray ba("user ");
        ba.append(userName);
        ba.append(" pass -1 vers mycode 007\n");
        this->write(ba);
    }
    else
    {
        status = "Error: unable to authenticate";
        emit sendStatus(status);
    }
}

void MySocket::processMessage()
{
    QByteArray msg = this->readLine();
    msg.chop(2);
    emit sendPacket(msg);
}

void MySocket::sendConnected()
{
    QByteArray status = "Connected";
    emit sendStatus(status);
}

void MySocket::sendDisconnected()
{
    QByteArray status = "Disconnected";
    emit sendStatus(status);
}
