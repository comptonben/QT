#ifndef BIG_ENEMY_H
#define BIG_ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTimer>
#include <stdlib.h>

#include "defs.h"

class Big_Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Big_Enemy();

private slots:
    void move();

private:
    QPixmap enemyPix[4];
    int random = rand() % (YMAX -200);
};

#endif // BIG_ENEMY_H
