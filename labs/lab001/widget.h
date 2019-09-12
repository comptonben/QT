#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

public slots:
    void writeMsg(QString s);
    void tbutton();
    void gbutton();
    void pbutton();
    void sbutton();
    void sendCustomSignal();

signals:
    void postBit(int b);
};

#endif // WIDGET_H
