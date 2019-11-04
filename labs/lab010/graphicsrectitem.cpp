#include "graphicsrectitem.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QList>

GraphicsRectItem::GraphicsRectItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
    this->setPen(QPen(Qt::blue));
    this->setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    dy = -2.0;
}

void GraphicsRectItem::advance(int phase)
{
    if (phase == 0)
        return;

    if(!scene()->collidingItems(this).isEmpty())
    {
        this->setPen(QPen(Qt::red));
        this->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    }
    else
    {
        this->setPen(QPen(Qt::blue));
        this->setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    }
    this->setRotation(this->rotation() + 2.0);
    if(this->scenePos().y() > -YMAX/2)
    {
        this->setPos(this->scenePos().x(), this->scenePos().y() + dy);
    }
    else if(this->scenePos().y() <= -YMAX/2)
    {
        delete this;
    }
}
