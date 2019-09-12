#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myUDPSocket = new QUdpSocket(this);
    myUDPSocket->bind(QHostAddress::LocalHost, 5678);

    connect(myUDPSocket, &QUdpSocket::readyRead,
            this, &MainWindow::processPendingDatagrams);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processPendingDatagrams()
{
    QByteArray mydatagram;

    while(myUDPSocket->hasPendingDatagrams())
    {
        mydatagram.resize(myUDPSocket->pendingDatagramSize());
        myUDPSocket->readDatagram(mydatagram.data(), mydatagram.size());
    }

    QString msg;
    QTextStream in(&mydatagram, QIODevice::ReadOnly);

    msg = in.readLine();
    ui->textBrowser->append(msg);
}
