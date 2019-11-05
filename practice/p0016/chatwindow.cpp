#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QKeyEvent>

ChatWindow::ChatWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatWindow)
{
    ui->setupUi(this);

    ui->chatEdit->installEventFilter(this);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

bool ChatWindow::eventFilter(QObject *watched, QEvent *e)
{
    if (!watched || !e) return QWidget::eventFilter(watched, e);

    if (watched == ui->chatEdit && e->type() == QEvent::KeyPress)
    {
        QKeyEvent *ke = static_cast<QKeyEvent*>(e);
        switch(ke->key())
        {
          case Qt::Key_0:
          case Qt::Key_1:
          case Qt::Key_2:
          case Qt::Key_3:
          case Qt::Key_4:
          case Qt::Key_5:
          case Qt::Key_6:
          case Qt::Key_7:
          case Qt::Key_8:
          case Qt::Key_9:   ui->conversationView->append(ke->text());
                            break;

          case Qt::Key_Enter:
          case Qt::Key_Return:  ui->chatEdit->clear();
                                return true;
        }
    }
    return QWidget::eventFilter(watched, e);
}
