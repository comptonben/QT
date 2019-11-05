#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

class Label : public QLabel
{
    Q_OBJECT

public:
    Label(QWidget * parent = nullptr);

protected:
    void mousePressEvent (QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
};

#endif // LABEL_H
