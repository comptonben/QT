#include "draglabel.h"

#include <QPixmap>
#include <QMouseEvent>
#include <QImage>
#include <QMimeData>
#include <QDrag>

DragLabel::DragLabel(const QString &path, QWidget *parent) :
    QLabel(parent)
{
    filename = path;
    this->setFixedSize(50, 50);
    setPixmap(QPixmap(filename));
}

void DragLabel::mousePressEvent(QMouseEvent *event)
{
    if (event && event->button() == Qt::LeftButton)
    {
        QMimeData* md = new QMimeData;
        QImage pic(filename);
        md->setImageData(pic);

        QDrag* drag = new QDrag(this);
        drag->setMimeData(md);

        if(pixmap())
        {
            QSize s = this->sizeHint();
            drag->setPixmap(pixmap()->scaled(s));
        }
        drag->start();
    }
}
