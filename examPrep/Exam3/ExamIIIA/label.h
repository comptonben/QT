#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QMimeData>
#include <QMouseEvent>
#include <QDrag>

class Label : public QLabel
{
    Q_OBJECT

public:
    Label(QString str, QWidget* parent=0);

protected:
    void mousePressEvent(QMouseEvent* e);
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);

private:

};

#endif // LABEL_H
