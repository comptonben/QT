#include "small_enemy.h"

Small_Enemy::Small_Enemy()
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
            i++;
        }
    }
    //////////////////////////////////////////////////////////////////

    //set pixmap
    this->setPixmap(enemyPix[0]);

    //set rand position
    this->setPos(x()-100, random);

    //timer to make move in 1 direction
    QTimer * t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    t->start(70);
}

void Small_Enemy::move()
{
    //bounce off right wall
    if(this->pos().x() > XMAX-110)
    {
        neg = rand() % 2;
        dx = dx * -1;
        dy = rand() % 12;

        if(neg == 1)
        {
            dy = dy * -1;
        }

        if(isRightFacing)
        {
            flip();
        }

        this->setPos(x()+dx, y() + dy);
    }
    //bounce off left wall
    else if(this->pos().x() < 0.0 && delay > 20)
    {
        neg = rand() % 2;
        dx = dx * -1;
        dy = rand() % 12;

        if(neg == 1)
        {
            dy = dy * -1;
        }

        if(!isRightFacing)
        {
            flip();
        }

        this->setPos(x() + dx, y() + dy);
    }
    //bounce off top wall
    else if(this->pos().y() < 0)
    {
        neg = rand() % 2;
        dx = rand() % 12;
        dy = dy * -1;

        if(neg == 1)
        {
            dx = dx * -1;
        }

        if(dx > 0.0 && !isRightFacing)
        {
            flip();
        }

        this->setPos(x()+dx, y() + dy);
    }
//    //bounce off bottom wall
    else if(this->pos().y() > YMAX - 85 )
    {
        neg = rand() % 2;
        dx = rand() % 12;
        dy = dy * -1;

        if(dx > 0.0 && !isRightFacing)
        {
            flip();
        }

        this->setPos(x()+dx, y() + dy);
    }
    else
    {
        this->setPos(x()+dx, y() + dy);

        //iterate through pic animations
        static int i = 0;
        this->setPixmap(enemyPix[i]);
        i++;

        if(i == 4)
        {
            i = 0;
        }
    }

    if(delay<50)
    {
        delay++;
    }

}

void Small_Enemy::flip()
{
    for(int i = 0; i < 4; i++)
    {
        enemyPix[i] = enemyPix[i].transformed(QTransform().scale(-1, 1));
    }

    isRightFacing = !isRightFacing;
}
