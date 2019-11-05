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
                md->setColorData(pixmap());
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

        if(md->hasColor() || md->hasText())
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

        if(md->hasColor())
        {
            pic = md->colorData().value<QPixmap>();
        }
        else
        {
            s = md->text();
        }
    }

    if(!pic.isNull())
    {
        setPixmap(pic);
    }
    else
    {
        setText(s);
    }
}
