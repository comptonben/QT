#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "label.h"

#include <QHostAddress>

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
    myTCP->connectToHost(QHostAddress::LocalHost, 5678);
    myTCP->waitForConnected();

    connect(myTCP, &QTcpSocket::readyRead, this, &MainWindow::processPendingDatagrams);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -150, 400, 300);
    scene->setBackgroundBrush(QBrush(Qt::black));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processPendingDatagrams()
{
    QByteArray msg = myTCP->readAll();
    msg.chop(2);
    QPixmap* pm = new QPixmap;
    pm->loadFromData(msg);
    QPainter p(pm);
    p.setPen(QPen(Qt::black));
    p.setFont(QFont("Helvetica", 96));
    QPoint tp(40, 40);
    p.drawText(tp, QString(msg.size()));
    pm->scaled(240, 180);
    ui->imageLabel->setPixmap(*pm);

}
