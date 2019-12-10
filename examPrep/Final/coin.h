#ifndef COIN_H
#define COIN_H

#include <QSqlQuery>
#include <QDebug>
#include <QByteArray>
#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class coin : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    coin(qreal x, qreal y, qreal dx, qreal dy);

public slots:
    void spin();

private:
    QPixmap coinPixmap[10];
};

#endif // COIN_H
