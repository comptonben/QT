#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    Ui::Dialog *ui;   /* On this exam, the form pointer UI must remain a public member of Dialog */

private slots:
    void mysteryButton();
    void toggleButton();
    void spawnButton();
    void winnerButton();
    void resetButton();

signals:
    void winnerStatus(bool status);
};

#endif // DIALOG_H
