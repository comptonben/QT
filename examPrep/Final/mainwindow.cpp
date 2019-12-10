#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coin.h"
#include "player.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QMYSQL");

    database.setHostName("mike");
    database.setPort(33200);
    database.setDatabaseName("2019cpe35302");
    database.setUserName("cpe35302");
    database.setPassword("6help6me6");

    if(!database.open())
    {
        qDebug() << "Error: Unable to open database...";
    }
    else
    {
        scene = new QGraphicsScene(-500, -350, 1024, 768, this);
        scene->setBackgroundBrush(QBrush(Qt::black));

        ui->graphicsView->setFixedSize(1100, 860);

        QSqlQuery q;

        if(!q.exec("SELECT * FROM walls"))
        {
            qDebug() << "Error: Cannot retrieve wall coordinates and sizes...";
        }
        else
        {
            while(q.next())
            {
                int xdir = q.value(0).toInt();
                int ydir = q.value(1).toInt();
                int w = q.value(2).toInt();
                int h = q.value(3).toInt();

                QGraphicsRectItem* rect = new QGraphicsRectItem(xdir, ydir, w, h);
                rect->setBrush(QBrush(Qt::blue));
                scene->addItem(rect);
            }
        }

        if(!q.exec("SELECT * FROM targetlocations"))
        {
            qDebug() << "Error: Cannot load data form table targetlocations...";
        }
        else
        {
            while(q.next())
            {
                static int i = 0;

                x[i] = q.value(0).toDouble();
                y[i] = q.value(1).toDouble();
                dx[i] = q.value(2).toDouble();
                dy[i] = q.value(3).toDouble();

                coin* object = new coin(x[i], y[i], dx[i], dy[i]);
                scene->addItem(object);

                i++;
            }


        }

        player *person = new player();
        scene->addItem(person);

        ui->graphicsView->setScene(scene);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
