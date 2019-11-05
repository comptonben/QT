#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow; }
QT_END_NAMESPACE

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *e);
    ~ChatWindow();

private:
    Ui::ChatWindow *ui;

};
#endif // CHATWINDOW_H
