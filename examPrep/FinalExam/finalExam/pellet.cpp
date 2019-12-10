#include "pellet.h"

Pellet::Pellet(int _x, int _y, int _w, int _h, int _r, int* _points)
    :QGraphicsRectItem(_x,_y,_w,_h)
{
    x=_x;
    y=_y;
    w=_w;
    h=_h;
    r=_r;

    points=_points;
}

QRectF Pellet::boundingRect() const
{
    qreal adjust = 1.0;
    return QRectF(-w-adjust, -h-adjust, w+adjust, h+adjust);
}

QPainterPath Pellet::shape() const
{
    QPainterPath path;
    path.addRect(-w,-h, w, h);
    return path;
}

void Pellet::advance(int phase)
{
    if(phase==0)
    {
        return;
    }
    else
    {
        QList<QGraphicsItem*> collisions = this->collidingItems();
        if (collisions.size()>0)
        {
            this->scene()->removeItem(this);
            (*points)=(*points)+100;
        }
        this->setRotation(this->rotation()+r);
    }
}
