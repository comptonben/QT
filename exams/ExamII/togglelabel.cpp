#include "togglelabel.h"
#include <QEvent>
#include <QMouseEvent>
#include <QtDebug>

ToggleLabel::ToggleLabel(QWidget *parent) : QLabel(parent)
{
    setPixmap(pm[count]);
}

void ToggleLabel::mousePressEvent(QMouseEvent *me)
{
    if(me && me->button() == Qt::RightButton)
    {
        if(count == 0)
        {
            count = 9;
        }
        else {
            count--;
        }
        setPixmap(pm[count]);
    }
    else if(me && me->button() == Qt::LeftButton)
    {
        if(count == 9)
        {
            count = 0;
        }
        else {
            count++;
        }
        setPixmap(pm[count]);
    }
    QLabel::mousePressEvent(me);
}

