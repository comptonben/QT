#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsItem>
#include <QColor>
#include <QPainter>
#include <QRectF>

class Target : public QGraphicsItem
{
public:
    Target();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget);

protected:
    void advance(int step);

private:
    qreal dx, dy;
    qreal x, y;
    qreal w, h;
};

#endif // TARGET_H
