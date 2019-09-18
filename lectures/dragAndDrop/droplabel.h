#ifndef DROPLABEL_H
#define DROPLABEL_H

#include <QtGui>
#include <QString>
#include <QWidget>
#include <QLabel>

class DropLabel : public QLabel
{
    Q_OBJECT

public:
    DropLabel(QWidget* parent = 0);

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
};

#endif // DROPLABEL_H
