#include "player.h"

player::player()
{
    QSqlQuery q;

    if(!q.exec("SELECT * FROM player"))
    {
        qDebug() << "Error: Could not retrieve data from player table...";
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            QByteArray dataArray = q.value(1).toByteArray();
            playerDown[i].loadFromData(dataArray, "PNG");
            q.next();
        }

        for(int i = 0; i < 3; i++)
        {
            QByteArray dataArray = q.value(1).toByteArray();
            playerLeft[i].loadFromData(dataArray);
            q.next();
        }

        for(int i = 0; i < 3; i++)
        {
            QByteArray dataArray = q.value(1).toByteArray();
            playerRight[i].loadFromData(dataArray);
            q.next();
        }

        for(int i = 0; i < 3; i++)
        {
            QByteArray dataArray = q.value(1).toByteArray();
            playerUp[i].loadFromData(dataArray);
            q.next();
        }
    }

    this->setTransformOriginPoint(40, 40);

    this->setPixmap(playerDown[0].scaled(80, 80, Qt::KeepAspectRatio));

    this->setPos(0, 0);

    QTimer *timer = new QTimer();
    timer->start(16);
}

void player::keyPressEvent(QKeyEvent* event)
{
    if(event && event->key() == Qt::Key_Up)
    {
       dy = -3;
       dx = 0;
    }

    else if(event && event->key() == Qt::Key_Down)
    {
        dy = 3;
        dx = 0;
    }

    else if(event && event->key() == Qt::Key_Right)
    {
        dx = 3;
        dy = 0;
    }
    else if(event && event->key() == Qt::Key_Left)
    {
        dx = -3;
        dy = 0;
    }
}
