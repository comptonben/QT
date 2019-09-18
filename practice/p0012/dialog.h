#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QQueue>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QQueue<QString> q;

    void showResult(QString& r);

private slots:
    void enqueue();
    void dequeue();
    void front();
    void rear();
    void size();
    void view();
    void clear();
};
#endif // DIALOG_H
