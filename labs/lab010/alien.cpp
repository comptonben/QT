#include "alien.h"
#include <QDebug>

Alien::Alien()
{
    dx = 1.00;
    dy = 25.00;
    w = 100.0;
    h = 72.0;
    x = -XMAX/2 + 2*w;
    y = -YMAX/2 + 2*h;

    index = 0;

    pmaps[0] = QPixmap(":/invader.png");
    pmaps[1] = QPixmap(":/invader.png");
    pmaps[2] = QPixmap(":/invader.png");
    pmaps[3] = QPixmap(":/invader.png");
    pmaps[4] = QPixmap(":/invader.png");
    pmaps[5] = QPixmap(":/invader.png");
    pmaps[6] = QPixmap(":/invader.png");
    pmaps[7] = QPixmap(":/invader.png");
}

void Alien::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    index = (index + 1) % 8;
    painter->drawPixmap(-w/2, -h/2, pmaps[index]);
}

QRectF Alien::boundingRect() const
{
    qreal adjust = 0.0;
    return QRectF(-w/2 - adjust, -h/2 - adjust, w + adjust, h + adjust);
}

void Alien::advance(int step)
{
    static QPointF startLocation = scenePos();
    const int xdelta = 375;
    if (step == 0)
        return;

    QPointF currentLocation = scenePos();

    if(dx > 0)
    {
        if(currentLocation.x() <= XMAX/2 - w/2 - 2)
        {

        }
        else if(currentLocation.x() > XMAX/2 - w/2 - 2)
        {
            dx = dx * -1.00;
            y = currentLocation.y() + dy;
        }
        x = currentLocation.x() + dx;
    }
    else if(dx < 0)
    {
        if(currentLocation.x() > (-XMAX/2 - w/2))
        {

        }
        else if(currentLocation.x() <= (-XMAX/2 + w/2))
        {
            dx = dx * -1.00;
            y = currentLocation.y() + dy;
        }
        x = currentLocation.x() + dx;
    }
    setPos(x, y);
}

QPainterPath Alien::shape() const
{
    QPainterPath path;
    path.addRect(-w/2, -h/2, w, h);
    return path;
}
