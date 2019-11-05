#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //P01
    socket= new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(loadImage()));
    socket->connectToHost(QHostAddress::LocalHost, 5678, QIODevice::ReadOnly);
    socket->waitForConnected();

    //P02
    connect(ui->goButton, SIGNAL(clicked(bool)), this, SLOT(makeLabels()));

    //P03
    //making the scene object
    scene= new QGraphicsScene(-200,-150,400,300);
    scene->setBackgroundBrush(QBrush(Qt::black));
    ui->graphicsView->setScene(scene);

    //making the clock face
    QGraphicsEllipseItem* face= new QGraphicsEllipseItem(-100,-100,200,200); //needs to have top corner at -100,-100
    face->setPen(QPen(Qt::blue));
    scene->addItem(face);
    for(int i=0; i<360; i=i+30)//ticks are 30 degrees apart
    {
        QGraphicsRectItem* tick= new QGraphicsRectItem(-3, -100, 5, 15);
        tick->setPen(QPen(Qt::blue));
        tick->setBrush(QBrush(Qt::blue));
        tick->setRotation(i);
        scene->addItem(tick);
    }

    //making the hands
    sec= new QGraphicsRectItem(-3,0,6,80);
    sec->setBrush(QBrush(Qt::red));
    sec->setRotation(180);
    scene->addItem(sec);
    min= new QGraphicsRectItem(-3,0,6,90);
    min->setBrush(QBrush(Qt::green));
    min->setRotation(180);
    scene->addItem(min);
    hour= new QGraphicsRectItem(-3,0,6,60);
    hour->setBrush(QBrush(Qt::white));
    hour->setRotation(180);
    scene->addItem(hour);

    //setting up the timer
    clock= new QTimer();
    clock->setInterval(1000); //1 sec interval
    connect(clock, SIGNAL(timeout()), this, SLOT(clockTick()));
    connect(ui->button, SIGNAL(clicked(bool)), this, SLOT(clockStartStop()));

    //slider
    connect(ui->slider, SIGNAL(valueChanged(int)), this, SLOT(clockSpeed(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//P01 Funcitons
void MainWindow::loadImage()
{
    QByteArray arr= socket->readAll();
    QPixmap pix;
    pix.loadFromData(arr);

    ui->imageLabel->setPixmap(pix.scaledToHeight(180).scaledToWidth(240));
    //ui->bytesLabel->setNum(arr.size());

    int size= arr.size();
    QString num= QString::number(size);
    ui->bytesLabel->setText(num);
}

//P02 Functions

//P03 Functions
void MainWindow::clockTick()
{
    sec->setRotation(sec->rotation()+6);
    min->setRotation(min->rotation()+.1);
    hour->setRotation(hour->rotation()+.0083333);
}

void MainWindow::clockStartStop()
{
    if (clock->isActive())
    {
        clock->stop();
        ui->button->setText("Stop");
    }
    else
    {
        clock->start();
        ui->button->setText("Start");
    }
}

void MainWindow::clockSpeed(int speed)
{
    clock->setInterval(1000/speed); //make the interval go by x(speed) faster
}

void MainWindow::makeLabels()
{
    QDialog* left= new QDialog(this);
    QVBoxLayout* leftlayout = new QVBoxLayout(left);
    Label* leftlabel = new Label(ui->leftEdit->text());
    leftlayout->addWidget(leftlabel);
    left->setLayout(leftlayout);
    left->show();
    ui->leftEdit->clear();

    QDialog* right= new QDialog(this);
    QVBoxLayout* rightlayout = new QVBoxLayout(right);
    Label* rightlabel = new Label(ui->rightEdit->text());
    rightlayout->addWidget(rightlabel);
    right->setLayout(rightlayout);
    right->show();
    ui->rightEdit->clear();
}
