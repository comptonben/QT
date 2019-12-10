#include "coin.h"

coin::coin(qreal x, qreal y, qreal dx, qreal dy)
{
    QSqlQuery q;

    if(!q.exec("SELECT * FROM target"))
    {
        qDebug() << "Error: Cannot retrieve data from table target...";
    }
    else
    {
        int i = 0;
        while(q.next())
        {
            QByteArray coinData = q.value(1).toByteArray();
            coinPixmap[i].loadFromData(coinData);
            i++;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        coinPixmap[i] = coinPixmap[i].scaled(60, 60, Qt::KeepAspectRatio);
    }

    this->setPos(x, y);

    this->setPixmap(coinPixmap[0]);

    this->setTransformOriginPoint(40, 40);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spin()));
    timer->start(40);
}

void coin::spin()
{
    static int i = 0;
    if(i < 10)
    {
        this->setPixmap(coinPixmap[i]);
        i++;
    }
    else
    {
        i = 0;
    }

}
