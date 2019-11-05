#include "label.h"
#include <QtDebug>

Label::Label(QString str, QWidget * parent) : QLabel(parent)
{
    this->setText(str);
    this->setAcceptDrops(true);
}

void Label::mousePressEvent(QMouseEvent* e)
{
    if(e && e->button() == Qt::LeftButton)
    {
        QMimeData* mime= new QMimeData;
        mime->setText(this->text());

        QDrag* drag= new QDrag(this);
        drag->setMimeData(mime);
        drag->start();
    }
}

void Label::dragEnterEvent(QDragEnterEvent* e)
{
    if(e && e->mimeData())
    {
        const QMimeData* mime= e->mimeData();

        if(mime->hasText())
        {
            e->acceptProposedAction();
        }
    }
}

void Label::dropEvent(QDropEvent* e)
{
    //QLabel text;

    if(e && e->mimeData())
    {
        const QMimeData* mime= e->mimeData();

        if(mime->hasText())
        {
            this->setText(mime->text());
        }
    }
}
