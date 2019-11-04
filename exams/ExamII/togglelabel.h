#ifndef TOGGLELABEL_H
#define TOGGLELABEL_H

#include <QLabel>
#include <QPixmap>

const int NUM_IMAGES = 10;

class ToggleLabel : public QLabel
{
    Q_OBJECT

public:
    ToggleLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *me);

private:
    int count = 0;
    QPixmap pm[10] = {QPixmap(":/images/0.png"), QPixmap(":/images/1.png"),
                      QPixmap(":/images/2.png"), QPixmap(":/images/3.png"),
                      QPixmap(":/images/4.png"), QPixmap(":/images/5.png"),
                      QPixmap(":/images/6.png"), QPixmap(":/images/7.png"),
                      QPixmap(":/images/8.png"), QPixmap(":/images/9.png")
                     };

    /************************************************************************/
    /*******                                                         ********/
    /*******  DO NOT CREATE CUSTOM SIGNALS OR SLOTS FOR ToggleLabel  ********/
    /*******                                                         ********/
    /************************************************************************/
};

#endif // TOGGLELABEL_H
