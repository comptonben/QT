#ifndef DADLABEL_H
#define DADLABEL_H

#include <QtGui>
#include <QString>
#include <QWidget>
#include <QLabel>

class DaDLabel : public QLabel
{
public:
    DaDLabel(const QString& path, QWidget* parent = 0);

protected:
    void mousePressEvent (QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

private:
    QString filename;
};

#endif // DADLABEL_H
