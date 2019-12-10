#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QTableView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QDateEdit>
#include <QGroupBox>

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
    QSqlDatabase db;
    QSqlQueryModel* model;
    QTableView* view;
    QVBoxLayout* mainLayout;
    QHBoxLayout* statusLayout;
    QHBoxLayout* editLayout;
    QHBoxLayout* buttonLayout;
    QPushButton* submitButton;
    QPushButton* quitButton;
    QLabel* label;
    QLabel* balanceLabel;
    QDateEdit* dateEdit;
    QLineEdit* descEdit;
    QLineEdit* amountEdit;
    QRadioButton* radio1;
    QRadioButton* radio2;

public slots:
    void SubmitQuery();
    void ShutDownGracefully();

};
#endif // DIALOG_H
