#include "dialog.h"
#include "ui_dialog.h"
#include <QtDebug>
#include <QSqlQuery>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->exportButton, &QPushButton::clicked, this, &Dialog::exportTable);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::exportTable()
{
    source = QSqlDatabase::addDatabase("QSQLITE", "sourcedb");
    destination = QSqlDatabase::addDatabase("QSQLITE", "destdb");

    if( ui->sourceEdit->text().isEmpty() ||
        ui->destEdit->text().isEmpty() ||
        ui->tableEdit->text().isEmpty() ||
        ui->leftEdit->text().isEmpty() ||
        ui->rightEdit->text().isEmpty())
    {
        qDebug() << "Error - enter names for both database files, the table name, and both column names";
        return;
    }

    source.setDatabaseName(ui->sourceEdit->text());
    destination.setDatabaseName(ui->destEdit->text());

    if(source.open() && destination.open())
    {
        qDebug() << "Source and Destination databases open";
        QSqlQuery sourceq(source);
        QString s = QString("SELECT * FROM %1").arg(ui->tableEdit->text());
        sourceq.prepare(s);
        qDebug() << s;
        if(sourceq.exec())
        {
            QSqlQuery destq(destination);
            QString s = QString("CREATE TABLE %1 (%2 INT, %3 INT)").arg(ui->tableEdit->text()).arg(ui->leftEdit->text()).arg(ui->rightEdit->text());
            destq.prepare(s);
            if(!destq.exec())
            {
                qDebug() << "Error - unable to create table in destination database";
                source.close();
                destination.close();
                return;
            }
            while(sourceq.next())
            {
                QString s = QString("INSERT INTO %1 VALUES (:left, :right)").arg(ui->tableEdit->text());
                qDebug() << s;
                destq.prepare(s);
                destq.bindValue(":left", sourceq.value(0).toInt());
                destq.bindValue(":right", sourceq.value(1).toInt());
                if(!destq.exec())
                {
                    qDebug() << "Error - unable to insert row into destination database";
                    source.close();
                    destination.close();
                    return;
                }
            }
        }
        else
        {
            qDebug() << "Error - unable to access specified table in source database";
            source.close();
            destination.close();
            return;
        }
    }
    else
    {
        qDebug() << "Error: unable to open both databases";
    }
}
