#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    points=0;

    //set up database
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../sprites.db");

    //set up scene for game, attach score
    scene= new QGraphicsScene(-1024/2, -768/2, 1024, 768);
    scene->setBackgroundBrush(QBrush(Qt::black));
    ui->graphicsView->setScene(scene);
    score= new QLabel("0");
    statusBar()->addWidget(score);

    if(!db.open())
    {
        qDebug() <<"Cannot open database";
    }

    //getting sprites from the database
    QSqlQuery q;
    if(q.exec("SELECT * FROM walls"))
    {
        while (q.next())
        {
            walls= new QGraphicsRectItem(q.value(0).toInt(), q.value(1).toInt(),
                                         q.value(2).toInt(), q.value(3).toInt());
            walls->setBrush(QBrush(Qt::blue));
            this->scene->addItem(walls);
        }
    }
    if(q.exec("SELECT * FROM pellets"))
    {
        while (q.next())
        {
            temp_pellet= new Pellet(-q.value(2).toInt(), -q.value(3).toInt(), q.value(2).toInt(),
                                q.value(3).toInt(), q.value(4).toInt(), &points);
            temp_pellet->setPos(q.value(0).toInt(), q.value(1).toInt());
            temp_pellet->setBrush(QBrush(Qt::green));
            scene->addItem(temp_pellet);
            pellets.append(temp_pellet);
        }
    }
    if(q.exec("SELECT * FROM cat"))
    {
        while (q.next())
        {
            pix= new QPixmap;
            pix->loadFromData(q.value(0).toByteArray());
            catpixs.append(pix);
        }
    }

    //create the cat
    cat= new Cat(catpixs);
    scene->addItem(cat);

    //set up timer
    timer= new QTimer(this);
    timer->setInterval(12);
    timer->start();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this, SLOT(addScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    if(e!=NULL)
    {
//        if(e->key()==Qt::Key_I)
//        {
//            cat->direction("up");
//        }
//        else if(e->key()==Qt::Key_J)
//        {
//            cat->direction("left");
//        }
//        else if(e->key()==Qt::Key_K)
//        {
//            cat->direction("down");
//        }
//        else if(e->key()==Qt::Key_L)
//        {
//            cat->direction("right");
//        }



        if(e->key()==Qt::Key_W)
        {
            cat->direction("up");
        }
        else if(e->key()==Qt::Key_A)
        {
            cat->direction("left");
        }
        else if(e->key()==Qt::Key_S)
        {
            cat->direction("down");
        }
        else if(e->key()==Qt::Key_D)
        {
            cat->direction("right");
        }


//        if(e->key()==Qt::Key_Up)
//        {
//            cat->direction("up");
//        }
//        else if(e->key()==Qt::Key_Left)
//        {
//            cat->direction("left");
//        }
//        else if(e->key()==Qt::Key_Down)
//        {
//            cat->direction("down");
//        }
//        else if(e->key()==Qt::Key_Right)
//        {
//            cat->direction("right");
//        }
        else
        {
            cat->direction("stop");
        }
    }
    QMainWindow::keyPressEvent(e);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    QKeyEvent *keyEvent;
    bool result = false;
    if (event->type() == QEvent::KeyPress)
    {
         keyEvent = dynamic_cast<QKeyEvent*>(event);
         this->keyPressEvent(keyEvent);
         result = true;
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        keyEvent = dynamic_cast<QKeyEvent*>(event);
        this->keyReleaseEvent(keyEvent);
        result = true;
    }
    else
        result = QObject::eventFilter(obj, event);

    return result;
}

void MainWindow::addScore()
{
    score->setNum(points);
}
