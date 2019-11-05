#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel(this);
    setCentralWidget(label);
    QPixmap myMap(600,480);
    myMap.fill(Qt::gray);
    label->setPixmap(myMap);

    QPixmap *redPix = new QPixmap(25, 25);
    redPix->fill(Qt::red);
    QPixmap *greenPix = new QPixmap(25, 25);
    greenPix->fill(Qt::green);
    QPixmap *bluePix = new QPixmap(25, 25);
    bluePix->fill(Qt::blue);

    red = new QAction(QIcon(*redPix), "Red", this);
    green = new QAction(QIcon(*greenPix), "Green", this);
    blue = new QAction(QIcon(*bluePix), "Blue", this);

    connect(red, &QAction::triggered, this, &MainWindow::redCircle);
    connect(green, &QAction::triggered, this, &MainWindow::greenSquare);
    connect(blue, &QAction::triggered, this, &MainWindow::bluePolygon);

    ui->toolBar->addAction(red);
    ui->toolBar->addAction(green);
    ui->toolBar->addAction(blue);
    ui->toolBar->setIconSize(QSize(25,25));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redCircle()
{
    QPixmap myMap(600, 480);
    myMap.fill(Qt::gray);
    QPainter p(&myMap);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::FlatCap));
    QRect rect1(125,75, 150, 150);
    p.drawEllipse(rect1);
    label->setPixmap(myMap);
}

void MainWindow::greenSquare()
{
    QPixmap myMap(600, 480);
    myMap.fill(Qt::gray);
    QPainter p(&myMap);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::green, 10, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    QRect rect1(125,75, 150, 150);
    p.drawRect(rect1);
    label->setPixmap(myMap);
}

void MainWindow::bluePolygon()
{
    QPixmap myMap(600, 480);
    myMap.fill(Qt::gray);
    QPainter p(&myMap);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(Qt::blue, 10, Qt::SolidLine, Qt::FlatCap));
    p.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    QPoint points[4] = {QPoint(200,100), QPoint(215,175), QPoint(200,150), QPoint(185,175)};
    p.drawPolygon(points, 4);
    label->setPixmap(myMap);
}
