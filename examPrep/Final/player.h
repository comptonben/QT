#ifndef PLAYER_H
#define PLAYER_H

#include <QSqlQuery>
#include <QDebug>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>

class player : public QObject, public QGraphicsPixmapItem
{
public:
    player();

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    void gameOver();
    QPixmap playerDown[3];
    QPixmap playerUp[3];
    QPixmap playerLeft[3];
    QPixmap playerRight[3];
    int dx = 0;
    int dy = 0;
};

#endif // PLAYER_H
