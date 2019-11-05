#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "label.h"

#include <QNetworkProxy>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /******* Populate grid layout with custom Label objects *******/
    for(int r = 0; r < 2; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            Label* pmLabel = new Label(this);
            pmLabel->setFrameStyle(QFrame::WinPanel);
            QPixmap* pm = new QPixmap(60,60);
            if (r%2 == 0) pm->fill(Qt::blue); else pm->fill(Qt::white);
            pmLabel->setPixmap(*pm);
            ui->gridLayout->addWidget(pmLabel, r, c);
            connect(pmLabel, SIGNAL(sendStatus(QString &)), this, SLOT(updateStatus(QString&)));
        }
    }
    /*********** Do not modify or delete the above code **********/

    socket = new QTcpSocket(this);
    socket->setProxy(QNetworkProxy::NoProxy);
    socket->connectToHost(QHostAddress::LocalHost, 5678, QIODevice::ReadOnly);
    socket->waitForConnected();

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::processPendingDatagrams);

    QPixmap *box = new QPixmap(300, 150);
    box->fill(Qt::red);
    ui->imageLabel->setPixmap(*box);

    scene= new QGraphicsScene(-200,-150,400,300);
    scene->setBackgroundBrush(QBrush(Qt::black));
    ui->graphicsView->setScene(scene);

    QGraphicsEllipseItem* clockFace= new QGraphicsEllipseItem(-100,-100,200,200); //needs to have top corner at -100,-100
    clockFace->setPen(QPen(Qt::blue));
    scene->addItem(clockFace);
    for(int i=0; i<360; i=i+30)//ticks are 30 degrees apart
    {
        QGraphicsRectItem* tick= new QGraphicsRectItem(-3, -100, 5, 15);
        tick->setPen(QPen(Qt::blue));
        tick->setBrush(QBrush(Qt::blue));
        tick->setRotation(i);
        scene->addItem(tick);
    }

    secHand= new QGraphicsRectItem(-3,0,6,80);
    secHand->setBrush(QBrush(Qt::red));
    secHand->setRotation(180);
    scene->addItem(secHand);
    minHand= new QGraphicsRectItem(-3,0,6,90);
    minHand->setBrush(QBrush(Qt::green));
    minHand->setRotation(180);
    scene->addItem(minHand);
    hourHand= new QGraphicsRectItem(-3,0,6,60);
    hourHand->setBrush(QBrush(Qt::white));
    hourHand->setRotation(180);
    scene->addItem(hourHand);

    clock= new QTimer();
    clock->setInterval(1000);
    connect(clock, SIGNAL(timeout()), this, SLOT(clockMove()));
    connect(ui->button, &QPushButton::clicked, this, &MainWindow::clockStart);
    connect(ui->slider, &QSlider::valueChanged, this, &MainWindow::clockSpeed);

    statusLabel = new QLabel("Ready");
    statusLabel->setFrameStyle(QFrame::WinPanel);
    statusBar()->addWidget(statusLabel);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStatus(QString& s)
{
    statusLabel->setText(s);
}

void MainWindow::processPendingDatagrams()
{
    QByteArray msg = socket->readAll();
    QPixmap* pm = new QPixmap(300, 150);
    pm->fill(Qt::blue);
    QPainter p(pm);
    p.setPen(QPen(Qt::white));
    p.setFont(QFont("Arial", 18));
    p.drawText(120, 120, msg);
    ui->imageLabel->setPixmap(*pm);
}

void MainWindow::clockMove()
{
    secHand->setRotation(secHand->rotation()+6);
    minHand->setRotation(minHand->rotation()+0.1);
    hourHand->setRotation(hourHand->rotation()+0.00833);
}

void MainWindow::clockStart()
{
    if(ui->button->text() == "Start")
    {
        clock->start();
        ui->button->setText("Stop");
    }
    else if(ui->button->text() == "Stop")
    {
        clock->stop();
        ui->button->setText("Start");
    }
}

void MainWindow::clockSpeed()
{
    switch(ui->slider->value())
    {
    case 1: clock->setInterval(1000);
            break;
    default: clock->setInterval(1000/(ui->slider->value()*6));
    }
}
