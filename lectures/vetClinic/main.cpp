#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication myApp(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("vetClinic.db");

    if(!db.open())
    {
        qDebug() << db.lastError();
        qDebug() << "Error: Unable to connect";
        return 1;
    }

    // Create query and use exec call to hand it an argument and execute it
    QSqlQuery q;

    q.exec("SELECT * FROM pets WHERE type='Dog'");

    while(q.next())
    {
        qDebug() << "UID=" << q.value(0).toInt()
                 << "  PetName=" << q.value(1).toString()
                 << "  Type=" << q.value(2).toString();
    }
    qDebug() << endl;

    // Create query object and execute it immediately
    QSqlQuery q2("SELECT * FROM customers WHERE lastName='Smith'");

    if(!q2.isActive())
    {
        qDebug() << q2.lastError();
        qDebug() << "Error: Unable to complete query";
        return 1;
    }
    while(q2.next())
    {
        qDebug() << "UID=" << q2.value(0).toInt()
                 << "  lastName=" << q2.value(1).toString()
                 << "  firstName=" << q2.value(2).toString();
    }
    qDebug() << endl;

    // Create poorly formed SQL query and attempt to execute it
    QSqlQuery q3("SELECT * FROM goats");
    if(!q3.isActive())
    {
        qDebug() << q3.lastError();
        qDebug() << "Deliberate failed SQL query";
    }
    qDebug() << endl;

    // Create query using placeholders for actual values
    // Bind values to the placeholders at runtime
    // Execute query

    // METHOD 1: named placeholders
    QSqlQuery q4;
    q4.prepare("INSERT INTO pets VALUES (:uid, :petname, :type)");
    q4.bindValue(":uid", 999);
    q4.bindValue(":petname", "Jaws");
    q4.bindValue(":type", "Shark");
    if(!q4.exec())
    {
        qDebug() << q4.lastError();
        qDebug() << "Error on INSERT";
        return 1;
    }
    qDebug() << endl;

    //METHOD 2: unnamed placeholders **ORDER MATTERS**
    q4.prepare("INSERT INTO pets VALUES (?, ?, ?)");
    q4.addBindValue(999);
    q4.addBindValue("Jaws");
    q4.addBindValue("Shark");
    if(!q4.exec())
    {
        qDebug() << q4.lastError();
        qDebug() << "Error on INSERT";
        return 1;
    }
    qDebug() << endl;

    QSqlQuery q5("SELECT * FROM pets;");
    while(q5.next())
    {
        qDebug() << "UID=" << q5.value(0).toInt()
                 << "  PetName=" << q5.value(1).toString()
                 << "  Type=" << q5.value(2).toString();
    }
    qDebug() << endl;

    q5.exec("UPDATE pets SET type='Goldfish' WHERE petName='Jaws'");
    q5.exec("SELECT * FROM pets");
    while(q5.next())
    {
        qDebug() << "UID=" << q5.value(0).toInt()
                 << "  PetName=" << q5.value(1).toString()
                 << "  Type=" << q5.value(2).toString();
    }
    qDebug() << endl;

    q5.exec("DELETE FROM pets WHERE petName='Jaws'");
    q5.exec("SELECT * FROM pets");
    while(q5.next())
    {
        qDebug() << "UID=" << q5.value(0).toInt()
                 << "  PetName=" << q5.value(1).toString()
                 << "  Type=" << q5.value(2).toString();
    }
    qDebug() << endl;


}
