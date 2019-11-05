#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QTcpSocket>

class MySocket : public QTcpSocket
{
public:
    MySocket();

public slots:
    void connectToARPSServer(const QString &hostName, quint16 port);
    void sendAuthentication(const QString &username);
    void processMessage();
    void sendConnected();
    void sendDisconnected();

signals:
    void sendStatus(QString);
    void sendPacket(QByteArray);
};

#endif // MYSOCKET_H
