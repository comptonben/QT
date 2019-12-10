#ifndef CAT_H
#define CAT_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPixmap>
#include <QVector>
#include <QPainter>
#include <QGraphicsScene>

class Cat : public QGraphicsItem
{
public:
    Cat(QVector<QPixmap*>);
    QRectF boundingRect() const;
    void advance(int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void direction(QString);

private:
    QPixmap cat[12];
    qreal x,y,w,h;
    qreal dx, dy;
    int offset;
    int index;
    QPointF wallpos;

signals:
    void collision();

};

#endif // CAT_H
