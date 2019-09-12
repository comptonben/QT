#ifndef SENDERDIALOG_H
#define SENDERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QUdpSocket>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class SenderDialog;
}

class SenderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SenderDialog(QWidget *parent = nullptr);
    ~SenderDialog();

private:
    Ui::SenderDialog *ui;
    QLabel* label;
    QLineEdit* lineEdit;
    QPushButton* sendButton;
    QPushButton* quitButton;

    QVBoxLayout* mainLayout;
    QHBoxLayout* editLayout;
    QHBoxLayout* buttonLayout;

    QUdpSocket* sendSocket;

private slots:
    void writeMessage();
};

#endif // SENDERDIALOG_H
