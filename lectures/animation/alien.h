#ifndef ALIEN_H
#define ALIEN_H

#include <QGraphicsItem>
#include <QColor>
#include <QPainter>
#include <QRect>

class Alien : public QGraphicsItem
{
public:
    explicit Alien();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget);

protected:
    void advance(int step);

private:
    QPixmap pmaps[8];
    qreal dx, dy;
    qreal x, y;
    qreal w, h;
    int index;
};

#endif // ALIEN_H
