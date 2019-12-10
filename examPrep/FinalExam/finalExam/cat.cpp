#include "cat.h"

Cat::Cat(QVector<QPixmap*> pixs)
    : QGraphicsItem()
{
    x=-1024/2;
    y=-768/2;
    w=80;
    h=80;
    index=0;
    offset=0;
    dx=0;
    dy=0;

    wallpos.setX(0);
    wallpos.setY(0);

    for(int i=0; i<pixs.size(); i++)
    {
        cat[i]=*pixs.at(i);
    }
}

QRectF Cat::boundingRect() const
{
    qreal adjust=0.0;
    return QRectF(-w/2-adjust, -h/2-adjust, w+adjust, h+adjust);
}

void Cat::advance(int phase)
{
    if(phase==0)
        return;
    else
    {
        this->moveBy(dx,dy);
        QList<QGraphicsItem*> collisions = this->collidingItems();
        if (collisions.size()>0)
        {
            for(int i=0; i<collisions.size(); i++)
            {
                if(collisions.at(i)->pos() == wallpos)
                {
                    this->moveBy(-dx,-dy);
                }
            }
        }
    }

}

void Cat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0)
{
    index++;
    index=offset+(index%3);
    painter->drawPixmap(-w/2, -h/2, cat[index].scaled(80,80));
}

void Cat::direction(QString dir)
{
    if(dir=="up")
    {
        offset=9;
        dx=0;
        dy=-5;
    }
    else if(dir=="left")
    {
        offset=3;
        dx=-5;
        dy=0;
    }
    else if(dir=="down")
    {
        offset=0;
        dx=0;
        dy=5;
    }
    else if(dir=="right")
    {
        offset=6;
        dx=5;
        dy=0;
    }
    else //dir==stop
    {
        //leave cat running it same direction it was
        dx=0;
        dy=0;
    }
}
