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
    scene->setBackgroundBrush(Qt::blue);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    p = new Projectile;
    p->setPos(-200, -150);
    scene->addItem(p);

    t = new Target;
    t->setPos(-200, 100);
    scene->addItem(t);

    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->setInterval(1000/33);
    timer->start();
}

Dialog::~Dialog()
{
    delete ui;
}

