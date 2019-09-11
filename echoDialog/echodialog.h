#ifndef ECHODIALOG_H
#define ECHODIALOG_H

#include <QDialog>

namespace Ui {
class EchoDialog;
}

class EchoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EchoDialog(QWidget *parent = nullptr);
    ~EchoDialog();

private:
    Ui::EchoDialog *ui;
};

#endif // ECHODIALOG_H
