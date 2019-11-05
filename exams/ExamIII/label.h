#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
#include <QtDebug>
#include <QFile>
#include <QMessageBox>

class Label : public QLabel
{
    Q_OBJECT

public:
    Label(QWidget * parent = nullptr);

protected:
    void mousePressEvent (QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

private:

signals:
    void sendStatus(QString& s);

public slots:
};

#endif // LABEL_H
