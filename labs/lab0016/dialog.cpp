#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->insertButton, &QPushButton::clicked, this, &Dialog::addImage);
    connect(ui->insertButton, &QPushButton::clicked, this, &Dialog::findImage);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("image.db");

    if(!db.open())
    {
        qDebug() << "Error: unable to open database";
        return;
    }

    QSqlQuery q("DROP TABLE icons");
    q.prepare("CREATE TABLE icons ( name TEXT, size INT, sprite BLOB )");

    if(!q.exec())
    {
        qDebug() << "Error: unable to create table";
        return;
    }

    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM icons");
    ui->tableView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addImage()
{
    QFile file(ui->fileEdit->text());

    if(!file.open(QIODevice::ReadOnly))
        return;

    QByteArray ba = file.readAll();
    QSqlQuery q;
    q.prepare("INSERT INTO icons VALUES( :name, :size, :image )");
    q.bindValue(":name", ui->indexEdit->text());
    q.bindValue(":size", file.size());
    q.bindValue(":image", ba);

    if(!q.exec())
    {
        QMessageBox msgBox;
        msgBox.setText("Error: unable to insert row");
        msgBox.exec();
    }
    else {
        model->setQuery("SELECT * FROM icons");
    }
}

void Dialog::findImage()
{
    QSqlQuery q;
    q.prepare("SELECT * FROM icons WHERE name=:name");
    q.bindValue(":name", ui->searchEdit->text());

    if(!q.exec())
    {
        QMessageBox msgBox;
        msgBox.setText("Error: unable to search");
        msgBox.exec();
    }
    else {
        while(q.next())
        {
            QDialog* d = new QDialog(this);
            QVBoxLayout* layout = new QVBoxLayout(d);
            QLabel* label = new QLabel(this);
            layout->addWidget(label);
            QPixmap temp;
            temp.loadFromData(q.value(2).toByteArray());
            label->setPixmap(temp);
            d->show();
        }
    }
}
