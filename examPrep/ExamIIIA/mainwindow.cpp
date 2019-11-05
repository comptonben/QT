#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "label.h"

#include <QHostAddress>
#include <QNetworkProxy>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /******* Populate grid layout with custom Label objects *******/
    for(int r = 0; r < 3; r++)
    {
        Label* tLabel = new Label(this);
        tLabel->setText(QString::number(r));
        tLabel->setFrameStyle(QFrame::Panel);
        ui->gridLayout->addWidget(tLabel, r, 0);
        Label* pLabel = new Label(this);
        pLabel->setFrameStyle(QFrame::Panel);
        QPixmap* pm = new QPixmap(50,50);
        pm->fill(Qt::blue);
        pLabel->setPixmap(*pm);
        ui->gridLayout->addWidget(pLabel, r, 1);
    }
    /*********** Do not modify or delete the above code **********/

    myTCP = new QTcpSocket(this);
    myTCP->setProxy(QNetworkProxy::NoProxy);
    myTCP->connectToHost(QHostAddress::LocalHost, 5678, QIODevice::ReadOnly);
    myTCP->waitForConnected();

    connect(myTCP, &QTcpSocket::readyRead, this, &MainWindow::processPendingDatagrams);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -150, 400, 300);
    scene->setBackgroundBrush(QBrush(Qt::black));
    ui->graphicsView->setScene(scene);

    QGraphicsEllipseItem *whiteCircle = new QGraphicsEllipseItem(-100, -100, 200, 200);
    whiteCircle->setPen(QPen(Qt::white));
    scene->addItem(whiteCircle);

    QGraphicsEllipseItem *yellowSun = new QGraphicsEllipseItem(-20, -20, sunD, sunD);
    yellowSun->setPen(QPen(Qt::yellow));
    yellowSun->setBrush(QBrush(Qt::yellow));
    scene->addItem(yellowSun);

    redPlanet = new QGraphicsEllipseItem(redOrbit-(redD/2), 0, redD, redD);
    redPlanet->setPen(QPen(Qt::red));
    redPlanet->setBrush(QBrush(Qt::red));
    scene->addItem(redPlanet);

    bluePlanet = new QGraphicsEllipseItem(blueOrbit-(blueD/2), -20, blueD, blueD);
    bluePlanet->setPen(QPen(Qt::blue));
    bluePlanet->setBrush(QBrush(Qt::blue));
    scene->addItem(bluePlanet);

    greenPlanet = new QGraphicsEllipseItem(greenOrbit-(greenD/2), -30, greenD, greenD);
    greenPlanet->setPen(QPen(Qt::green));
    greenPlanet->setBrush(QBrush(Qt::green));
    scene->addItem(greenPlanet);

    timer = new QTimer(this);
    timer->setInterval(16.6667);

    connect(timer, SIGNAL(timeout()), this, SLOT(planetMove()));
    connect(ui->slider, &QSlider::valueChanged, this, &MainWindow::planetSpeed);
    connect(ui->button, &QPushButton::clicked, this, &MainWindow::startButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processPendingDatagrams()
{
    QByteArray msg = myTCP->readAll();
    QPixmap* pm = new QPixmap;
    pm->loadFromData(msg);
    QPainter p(pm);
    p.setFont(QFont("Helvetica", 96));
    QString size;
    size.setNum(msg.size());
    p.drawText(120, 120, size);
    QPixmap pic = pm->scaled(240, 180);
    ui->imageLabel->setPixmap(pic);

}

void MainWindow::planetMove()
{
    redPlanet->setRotation(redPlanet->rotation()+6);
    greenPlanet->setRotation(greenPlanet->rotation()+0.1);
    bluePlanet->setRotation(bluePlanet->rotation()+0.00833);
}

void MainWindow::planetSpeed()
{
    timer->setInterval(16.6667/ui->slider->value());
}

void MainWindow::startButton()
{
    if(ui->button->text() == "Start")
    {
        timer->start();
        ui->button->setText("Stop");
    }
    else if(ui->button->text() == "Stop")
    {
        timer->stop();
        ui->button->setText("Start");
    }
}
