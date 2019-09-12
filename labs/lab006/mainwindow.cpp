#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myTCPSocket = new QTcpSocket(this);
    myTCPSocket->connectToHost(QHostAddress::LocalHost, 5678);
    myTCPSocket->waitForConnected();

    connect(myTCPSocket, &QTcpSocket::readyRead,
            this, &MainWindow::processPendingDatagrams);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processPendingDatagrams()
{
    QString msg;
    QTextStream in(myTCPSocket);

    msg = in.readLine();
    ui->textBrowser->append(msg);
}
