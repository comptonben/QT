#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "defs.h"
#include "bullet.h"
#include "big_enemy.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QSqlQuery>
#include <QByteArray>
#include <QSqlError>
#include <QKeyEvent>
#include <QTimer>

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>

#include <QDebug>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();

protected:
    void keyPressEvent(QKeyEvent * event);

private slots:
    void move();

private:
    void endGame();
    int dx = 0, dy = 0;
    direction current_dir;
    QPixmap playerPixmap[16];
};

#endif // PLAYER_H
