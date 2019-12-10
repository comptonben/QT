#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsLineItem"

#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //config SQL
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("images.db");

    if(!db.open())
    {
        qDebug() << db.lastError();
    }
    else
    {

    //create the scene
    scene = new QGraphicsScene(0, 0, XMAX, YMAX, this);

    //make background image
    QSqlQuery query;
    query.exec("SELECT * FROM background_images");

    if(query.first())
    {
        QPixmap image;
        QByteArray outByteArray = query.value(1).toByteArray();
        image.loadFromData(outByteArray, "JPG");
        scene->setBackgroundBrush(QBrush(image.scaled(XMAX, YMAX)));
    }

    //set lines as borders
    QGraphicsLineItem * line1 = new QGraphicsLineItem(0, 0, XMAX, 0);
    QGraphicsLineItem * line2 = new QGraphicsLineItem(0, 0, 0, YMAX);
    QGraphicsLineItem * line3 = new QGraphicsLineItem(XMAX, YMAX, XMAX, 0);
    QGraphicsLineItem * line4 = new QGraphicsLineItem(XMAX, YMAX, 0, YMAX);

    line1->setPen(QPen(QColor(Qt::blue),5));
    line2->setPen(QPen(QColor(Qt::blue),5));
    line3->setPen(QPen(QColor(Qt::blue),5));
    line4->setPen(QPen(QColor(Qt::blue),5));

    scene->addItem(line1);
    scene->addItem(line2);
    scene->addItem(line3);
    scene->addItem(line4);

    //set fixed screen size
    ui->graphicsView->setFixedSize(XMAX+50, YMAX+50);

    //create and setup player instance
    Player * player = new Player();
    player->setPos(XMAX/2, YMAX/2);
    scene->addItem(player);

    //To make Key events work i need to foucs the item
    player->setFlag(QGraphicsItem::ItemIsFocusable); //makes it able to be focused
    player->setFocus(); //set to the focused item

    //add the scene to the graphicsView
    ui->graphicsView->setScene(scene);

    //timer for small enemy spawn
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(randomNumber);

    //timer for big enemy spawn
    QTimer * timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(spawnBigEnemy()));
    timer2->start(randmomNumber2);
    }

}

void MainWindow::spawnEnemy()
{
    Small_Enemy * enemy1 = new Small_Enemy();
    scene->addItem(enemy1);

}

void MainWindow::spawnBigEnemy()
{
    Big_Enemy * enemy = new Big_Enemy();
    scene->addItem(enemy);
}

MainWindow::~MainWindow()
{
    delete ui;
}
