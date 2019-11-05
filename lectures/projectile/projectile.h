#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsItem>
#include <QColor>
#include <QPainter>
#include <QRect>

class Projectile : public QGraphicsItem
{
public:
    explicit Projectile();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget);

protected:
    void advance(int step);

private:
    QColor color;
    qreal dx, dy;
    qreal x, y;
    qreal w, h;
};

#endif // PROJECTILE_H
