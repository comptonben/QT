#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

#include <QSqlQuery>
#include <QByteArray>
#include <QSqlError>

#include <QDebug>

#include "small_enemy.h"
#include "defs.h"

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(direction dir, QPointF pos);

private slots:
    void move();

private:
    direction dir;

};

#endif // BULLET_H
