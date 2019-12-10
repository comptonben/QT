#include "bullet.h"

Bullet::Bullet(direction curr_dir, QPointF pos)
{
    dir = curr_dir;
    //////////////////////////////////////////////////////////////////////
    //Query Database for images
    QPixmap BulletPixmap;

    QSqlQuery query;

    if(!query.exec( "SELECT * FROM bullet_images" ))
    {
        qDebug() << "Error getting image from table: " << query.lastError();
    }
    else
    {
        int i = 0;
        while(query.next())
        {
            QByteArray outByteArray = query.value(1).toByteArray();
            BulletPixmap.loadFromData(outByteArray, "PNG");
            i++;
        }
    }
    //////////////////////////////////////////////////////////////////////

    //set the pixmap with scale
    this->setPixmap(BulletPixmap.scaled(80, 80, Qt::KeepAspectRatio));

    //check which way character faces for accurate bullet placement
    if(curr_dir == l || curr_dir == down)
    {
            this->setPos(pos.x() - 30, (pos.y()+35));
    }
    else
    {
        this->setPos(pos.x() + 50, (pos.y()+35));
    }

    //set bullet rotation origin
    this->setTransformOriginPoint(35, 35);

    //setup and start Qtimer for movement
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //check if colliding with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Small_Enemy))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //set rotation
    this->setRotation(this->rotation() + 10.0);

    if(dir == up)
    {
        if(this->pos().y() < 0 - 100)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x(), y() - 20);
        }
    }
    else if (dir == l)
    {
        if(this->pos().x() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x() - 20, y());
        }
    }
    else if(dir == down)
    {
        if(this->pos().y() > YMAX)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x(), y()+20);
        }
    }
    else if(dir == r)
    {
        if(this->pos().x() > XMAX)
        {
            scene()->removeItem(this);
            delete this;
        }
        else
        {
            this->setPos(x()+20, y());
        }
    }
}
