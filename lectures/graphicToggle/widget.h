#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QPushButton
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *pe);

private:
    Ui::Widget *ui;
    QPixmap* redPixmap;
    QPixmap* blackPixmap;
    QPainter* painter;
    QIcon* redIcon;
    QIcon* blackIcon;
    bool illuminated;

private slots:
    void togglePixmap();
};
#endif // WIDGET_H
