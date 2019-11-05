#include "alien.h"

Alien::Alien()
{
    dx = 0.00;
    dy = 2.50;
    x = 0.0;
    y = 0.0;
    w = 100.0;
    h = 72.0;
    index = 0;
    pmaps[0] = QPixmap(":/images/invader1.png");
    pmaps[1] = QPixmap(":/images/invader1.png");
    pmaps[2] = QPixmap(":/images/invader1.png");
    pmaps[3] = QPixmap(":/images/invader1.png");
    pmaps[4] = QPixmap(":/images/invader2.png");
    pmaps[5] = QPixmap(":/images/invader2.png");
    pmaps[6] = QPixmap(":/images/invader2.png");
    pmaps[7] = QPixmap(":/images/invader2.png");
}

void Alien::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    index = (index + 1) % 8;
    painter->drawPixmap(-w/2, -h/2, pmaps[index]);
}

QRectF Alien::boundingRect() const
{
    qreal adjust = 1.0;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

void Alien::advance(int step)
{
    if(step == 0)
        return;

   x = this->pos().rx();
   y = this->pos().ry();

   x = x + dx;
   y = y + dy;

   setPos(x, y);
}

QPainterPath Alien::shape() const
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}

