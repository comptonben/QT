#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -150, 400, 300);
    scene->setBackgroundBrush(Qt::black);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    for(int i = 0; i < 4; i++)
    {
        aliens[i] = new Alien;
        aliens[i]->setPos(-190 + i * 125, -150);
        scene->addItem(aliens[i]);
    }

    QTimer* timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->setInterval(1000/33);
    timer->start();
}

Dialog::~Dialog()
{
    delete ui;
}

