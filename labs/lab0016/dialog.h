#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPixmap>
#include <QLabel>
#include <QFile>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QtDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QSqlDatabase db;
    QSqlQueryModel* model;

private slots:
    void addImage();
    void findImage();
};

#endif // DIALOG_H
