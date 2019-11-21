#include "dialog.h"
#include "ui_dialog.h"

#include <QtDebug>
#include <QSqlQuery>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->clearButton, &QPushButton::clicked, ui->lineEdit, &QLineEdit::clear);
    connect(ui->sendButton, &QPushButton::clicked, this, &Dialog::postQuery);

    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("Mike");
    db.setPort(3300);
    db.setDatabaseName("cpe353");
    db.setUserName("cpe353student");
    db.setPassword("123qwerty456");

    if(!db.open())
    {
        qDebug() << "Error: unable to connect to MySQL database";
        exit(1);
    }
    else
    {
        qDebug() << "Connected to MySQL database";
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::postQuery()
{
    QString s = ui->lineEdit->text();
    ui->clearButton->click();

    qDebug() << s;

    QSqlQuery q;
    q.prepare(s);

    if(q.exec())
    {
        qDebug() << "Query executed successfully";

        while(q.next())
        {
            qDebug() << q.value(0).toString() << q.value(1).toString()
                     << q.value(2).toString() << q.value(3).toString() << q.value(4).toString();
        }
    }
    else
    {
        qDebug() << "Error: query failed:   " << q.lastQuery();
    }
}
