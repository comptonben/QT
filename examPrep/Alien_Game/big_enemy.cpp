#include "big_enemy.h"

Big_Enemy::Big_Enemy()
{
    QSqlQuery query;

    if(!query.exec( "SELECT * FROM enemy_images" ))
    {
        qDebug() << "Error getting image from table: " << query.lastError();
    }
    else
    {
        int i = 0;
        while(query.next())
        {
            QByteArray outByteArray = query.value(1).toByteArray();
            enemyPix[i].loadFromData(outByteArray, "PNG");
            enemyPix[i] = enemyPix[i].scaled(250, 250, Qt::KeepAspectRatio);
            i++;
        }
    }
    //////////////////////////////////////////////////////////////////

    //set pixmap
    this->setPixmap(enemyPix[0]);

    //set rand position
    this->setPos(x() - 100, random);

    //timer to make move in 1 direction
    QTimer * t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    t->start(70);
}

void Big_Enemy::move()
{
    if(this->pos().x() > XMAX)
    {
        scene()->removeItem(this);
        delete this;
    }
    else
    {
        this->setPos(x()+12, y());
        //iterate through pic animations

        static int i = 0;
        this->setPixmap(enemyPix[i]);
        i++;
        if(i == 4)
        {
            i = 0;
        }
    }
}
