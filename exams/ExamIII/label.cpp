#include "label.h"

Label::Label(QWidget * parent) : QLabel(parent)
{
    setAcceptDrops(true);
}

void Label::mousePressEvent(QMouseEvent *event)
{
    if (event && event->button() == Qt::LeftButton)
        {
            QDrag* drag = new QDrag(this);
            QMimeData* md = new QMimeData();
            if(pixmap())
            {
                md->setImageData(pixmap()->toImage());
            }
            else
            {
                md->setText(text());
            }
            drag->setMimeData(md);
            drag->start();
        }
}

void Label::dragEnterEvent(QDragEnterEvent *event)
{
    if(event && event->mimeData())
    {
        const QMimeData* md = event->mimeData();

        if(md->hasImage() || md->hasText())
        {
            event->acceptProposedAction();
        }
    }
}

void Label::dropEvent(QDropEvent *event)
{
    QPixmap pic;
    QString s;
    if(event && event->mimeData())
    {
        const QMimeData* md = event->mimeData();

        if(md->hasImage())
        {
            pic = md->imageData().value<QPixmap>();
        }
        else
        {
            s = md->text();
            s.remove(0, 6);
            s.chop(2);
        }
    }

    if(!pic.isNull())
    {
        setPixmap(pic);
    }
    else
    {
        QFile imageFile(s);
        emit sendStatus(s);
        imageFile.open(QIODevice::ReadOnly);

        QByteArray ba = imageFile.readAll();
        QPixmap pm;
        pm.loadFromData(ba);
        pm = pm.scaled(60, 60);
        setPixmap(pm);

        imageFile.close();
    }
}
