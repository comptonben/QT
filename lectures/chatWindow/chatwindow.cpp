#include "chatwindow.h"

#include <QVBoxLayout>
#include <QSplitter>
#include <QEvent>
#include <QKeyEvent>

ChatWindow::ChatWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    QSplitter *splitter = new QSplitter(Qt::Vertical, this);
    lay->addWidget(splitter);

    conversationView = new QTextBrowser;
    chatEdit = new QTextEdit;

    splitter->addWidget(conversationView);
    splitter->addWidget(chatEdit);

    chatEdit->installEventFilter(this);

    setWindowTitle("Chat Window");
    setTabOrder(chatEdit, conversationView);
}

ChatWindow::~ChatWindow()
{

}

bool ChatWindow::eventFilter(QObject *watched, QEvent *e)
{
    if(watched == chatEdit && e->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent*>(e);

        if(ke->key() == Qt::Key_Enter || ke->key() == Qt::Key_Return)
        {
            submitChatText();
            return true;
        }
    }

    return QWidget::eventFilter(watched, e);
}

void ChatWindow::submitChatText()
{
    conversationView->append(chatEdit->toPlainText());
    chatEdit->setPlainText("");
}
