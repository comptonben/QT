#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkProxy>
#include <QtDebug>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aprs = new MySocket;
//    aprs->setProxy(QNetworkProxy::NoProxy);

    connect(ui->applyButton, &QPushButton::clicked, this, &MainWindow::applyConfiguration);
    connect(ui->defaultButton, &QPushButton::clicked, this, &MainWindow::defaultConfiguration);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearConfiguration);

    startAction = new QAction(QIcon(":/images/start.png"), "Start", this);
    connect(startAction, &QAction::triggered, this, &MainWindow::startReceiving);

    stopAction = new QAction(QIcon(":/images/stop.png"), "Stop", this);
    connect(stopAction, &QAction::triggered, this, &MainWindow::stopReceiving);

    clearAction = new QAction(QIcon(":/images/trash.png"), "Clear", this);
    connect(clearAction, &QAction::triggered, ui->textBrowser, &QTextBrowser::clear);

    saveAction = new QAction("Save", this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveLog);

    quitAction = new QAction("Quit", this);
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction, &QAction::triggered, this, &MainWindow::close);

    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);

    ui->mainToolBar->addAction(startAction);
    ui->mainToolBar->addAction(stopAction);
    ui->mainToolBar->addAction(clearAction);

    statusLabel = new QLabel("Ready", this);
    statusBar()->addWidget(statusLabel);

    connect(aprs, &MySocket::sendStatus, this, &MainWindow::postStatus);
    connect(aprs, &MySocket::sendPacket, this, &MainWindow::postPacket);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyConfiguration()
{
    servername = ui->serverEdit->text();
    username = ui->userEdit->text();
    port = ui->portEdit->text().toUInt();
}

void MainWindow::defaultConfiguration()
{
    ui->serverEdit->setText("blackhawk");
    ui->userEdit->setText("generic");
    ui->portEdit->setText("20152");
}

void MainWindow::clearConfiguration()
{
    ui->serverEdit->clear();
    ui->userEdit->clear();
    ui->portEdit->clear();
    applyConfiguration();
}

void MainWindow::startReceiving()
{
    if(aprs->state() == QAbstractSocket::UnconnectedState)
    {
        aprs->connectToARPSServer(servername, port);
        aprs->sendAuthentication(username);
    }
    ui->tabWidget->setTabEnabled(0, false);
}

void MainWindow::stopReceiving()
{
    if(aprs->state() == QAbstractSocket::ConnectedState)
    {
        aprs->disconnectFromHost();
    }
    ui->tabWidget->setTabEnabled(0, true);
}

void MainWindow::saveLog()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save File", "./untitled.txt", "Text files (*.txt)");
    QFile outputFile(filename);

    if(filename.isEmpty())
    {
        return;
    }
    else if(outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QByteArray ba = ui->textBrowser->toPlainText().toUtf8();
        outputFile.write(ba);
        outputFile.close();
    }
    else
    {
        qDebug() << "Error: unable to open output file";
    }
}

void MainWindow::postStatus(QString s)
{
    statusLabel->setText(s);
}

void MainWindow::postPacket(QByteArray s)
{
    ui->textBrowser->append(s);
}
