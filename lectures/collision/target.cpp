#include "target.h"
#include <QList>
#include <QGraphicsScene>

Target::Target()
{
    dx = 0.00;
    dy = 0.00;
    x = 0.0;
    y = 0.0;
    w = 40.0;
    h = 20.0;
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    static QColor color = Qt::green;
    if(!scene()->collidingItems(this).isEmpty())
    {
        color = Qt::red;
    }
    painter->setBrush(color);
    painter->drawRect(-w/2, -h/2, w, h);
}

QRectF Target::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

void Target::advance(int step)
{
    if(step == 0)
        return;

   x = this->pos().x();
   y = this->pos().y();

   x = x + dx;
   y = y + dy;

   setPos(x, y);
}

QPainterPath Target::shape() const
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}
