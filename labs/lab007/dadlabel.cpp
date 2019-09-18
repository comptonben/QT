#include "dadlabel.h"

DaDLabel::DaDLabel(const QString &path, QWidget *parent) :
    QLabel(parent)
{
    filename = path;
    this->setFixedSize(50, 50);
    setPixmap(QPixmap(filename));
    setAcceptDrops(true);
}

void DaDLabel::mousePressEvent(QMouseEvent *event)
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

void DaDLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if(event && event->mimeData())
    {
        const QMimeData* md = event->mimeData();

        if(md->hasImage())
        {
            event->acceptProposedAction();
        }
    }
}

void DaDLabel::dropEvent(QDropEvent *event)
{
    QPixmap pic;
    if(event && event->mimeData())
    {
        const QMimeData* md = event->mimeData();

        if(md->hasImage())
        {
            pic = md->imageData().value<QPixmap>();
        }
    }

    if(!pic.isNull())
    {
        setPixmap(pic);
    }
}

