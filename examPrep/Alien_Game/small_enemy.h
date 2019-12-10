#ifndef SMALL_ENEMY_H
#define SMALL_ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTimer>
#include <stdlib.h>

#include "defs.h"


class Small_Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Small_Enemy();

private slots:
    void move();

private:
    void flip();

    QPixmap enemyPix[4];
    int random = rand() % (YMAX - 200);
    int dy = 0;
    int dx = 12;
    int neg;
    int delay = 0;
    bool isRightFacing = true;
};

#endif // SMALL_ENEMY_H
