#ifndef MEMODIALOG_H
#define MEMODIALOG_H

#include <QDialog>

namespace Ui {
class MemoDialog;
}

class MemoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MemoDialog(QWidget *parent = nullptr);
    ~MemoDialog();

private:
    Ui::MemoDialog *ui;
};

#endif // MEMODIALOG_H
