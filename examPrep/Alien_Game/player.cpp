#include "player.h"

Player::Player()
{
   //////////////////////////////////////////////////////////////////////
   //Query Database for images

    QSqlQuery query;

    if(!query.exec( "SELECT * FROM player_images" ))
    {
       qDebug() << "Error getting image from table: " << query.lastError();
    }
    else
    {
       int i = 0;
       while(query.next())
       {
           QByteArray outByteArray = query.value(1).toByteArray();
           playerPixmap[i].loadFromData(outByteArray, "PNG");
           i++;
       }
    }
   //////////////////////////////////////////////////////////////////////

   //set pixmap
   this->setPixmap(playerPixmap[0]);

   //timer to make move in 1 direction
   QTimer * t = new QTimer();
   connect(t, SIGNAL(timeout()), this, SLOT(move()));
   t->start(60);
}

//moves the player with timer
void Player::move()
{
    //check if colliding with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for(int i = 0; i < colliding_items.size(); i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Big_Enemy))
        {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            endGame();
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //check direction and bounds
    if(scenePos().y() > 0 && current_dir == up)
    {
        setPos(this->pos().x() + dx, this->pos().y() + dy);

        //iterate through pic animations
        static int i = 0;
        this->setPixmap(playerPixmap[i%8]);
        i++;
        if(i == 16)
        {
            i = 0;
        }
    }
    else if(scenePos().x() > 0 && current_dir == l)
    {
        setPos(this->pos().x() + dx, this->pos().y() + dy);
        static int i = 8;
        this->setPixmap(playerPixmap[(i%8)+8]);
        i++;
        if(i == 32)
        {
            i = 8;
        }
    }
    else if(scenePos().y() +100 < YMAX && current_dir == down)
    {
        setPos(this->pos().x() + dx, this->pos().y() + dy);
        static int i = 8;
        this->setPixmap(playerPixmap[(i%8)+8]);
        i++;
        if(i == 32)
        {
            i = 8;
        }
    }
    else if(scenePos().x() +80 < XMAX && current_dir == r)
    {
        setPos(this->pos().x() + dx, this->pos().y() + dy);

        static int i = 0;
        this->setPixmap(playerPixmap[i%8]);
        i++;
        if(i == 16)
        {
            i = 0;
        }
    }
}

//handle key presses
void Player::keyPressEvent(QKeyEvent * event)
{
    if(event && event->key() == Qt::Key_W)
    {
        //move the item 10 pixles up from current position

        //setPos(this->pos().x(), this->pos().y()-20);
        dx = 0;
        dy = -10;
        current_dir = up;
    }
    else if (event && event->key() == Qt::Key_A)
    {
        //setPos(x()-20, y());
        dx = -10;
        dy = 0;
        current_dir = l;
    }
    else if(event && event->key() == Qt::Key_S)
    {
        //setPos(x(), y()+20);
        dx = 0;
        dy= 10;
        current_dir = down;
    }
    else if(event && event->key() == Qt::Key_D)
    {
        //setPos(x()+20, y());
        dx = 10;
        dy = 0;
        current_dir = r;
    }
    else if(event && event->key() == Qt::Key_Space)
    {
        if(!(current_dir == stop))
        {
            //relative pos of player
            QPointF currentpos = this->pos();

            //create the bullet
            //make bullet appear in middle of player
            //add to scene
            Bullet * bullet = new Bullet(current_dir, currentpos);
            scene()->addItem(bullet);
        }
    }
    else
    {
        //stop
        dx = 0;
        dy = 0;
        current_dir = stop;
    }

    QGraphicsPixmapItem::keyPressEvent(event);
}

void Player::endGame()
{
    QDialog * q = new QDialog();
    QHBoxLayout * l = new QHBoxLayout();
    QLabel * lab = new QLabel();

    q->setLayout(l);
    lab->setText("Game Over");
    l->addWidget(lab);

    q->exec();
}

