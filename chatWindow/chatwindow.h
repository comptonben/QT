#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include <QTextBrowser>
#include <QTextEdit>

class QTextBrowser;
class QTextEdit;
class QEvent;

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
    void submitChatText();
    bool eventFilter(QObject *watched, QEvent *e);

private:
    QTextBrowser *conversationView;
    QTextEdit *chatEdit;
};

#endif // CHATWINDOW_H
