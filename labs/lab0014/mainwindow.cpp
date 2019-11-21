#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    statusLabel = new QLabel("Ready");
    statusBar()->addWidget(statusLabel);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("custom.db");

    if(!db.open())
    {
        qDebug() << db.lastError();
        qDebug() << "Error: Unable to connect due to above error";
        return;
    }
    else
    {
        QSqlQuery q;
        if(!q.exec("CREATE TABLE grades (id INT, name TEXT, score INT)"))
        {
            qDebug() << db.lastError();
            qDebug() << "Error: Unable to create table due to above error";
        }
    }

    connect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::sqlInsert);
    connect(ui->cancelButton, &QPushButton::clicked, this, &MainWindow::sqlCancel);
    connect(ui->queryButton, &QPushButton::clicked, this, &MainWindow::sqlQuery);
    connect(ui->dropButton, &QPushButton::clicked, this, &MainWindow::sqlDrop);
    connect(ui->showButton, &QPushButton::clicked, this, &MainWindow::sqlShowAll);

    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM grades");
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sqlInsert()
{
    QSqlQuery q;
    q.prepare("INSERT INTO grades VALUE( :id , :name , :score )");
    bool ok1, ok2;
    q.bindValue(":id", ui->idLineEdit->text().toInt(&ok1, 10));
    q.bindValue(":name", ui->nameLineEdit->text());
    q.bindValue(":score", ui->scoreLineEdit->text().toInt(&ok2, 10));

    ui->idLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->scoreLineEdit->clear();

    if(!q.exec() || !ok1 || !ok2)
    {
        statusLabel->setText("Error executing INSERT");
        return;
    }
    else
    {
        statusLabel->setText("INSERT successful");
        model->setQuery("SELECT * FROM grades");
        ui->tableView->setModel(model);
    }
}

void MainWindow::sqlCancel()
{
    ui->idLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->scoreLineEdit->clear();

    statusLabel->setText("INSERT cancelled");
}

void MainWindow::sqlQuery()
{
    QSqlQuery q;
    QString s = QString("SELECT %1 FROM grades").arg(ui->selectLineEdit->text());
    if(ui->whereLineEdit->text() != "")
    {
        s.append(QString("WHERE %1").arg(ui->whereLineEdit->text()));
    }
    q.prepare(s);

    ui->selectLineEdit->clear();
    ui->whereLineEdit->clear();

    if(!q.exec())
    {
        statusLabel->setText("Error executing SELECT");
        return;
    }
    else
    {
        statusLabel->setText("SELECT successful");
        model->setQuery(q);
        ui->tableView->setModel(model);
    }
}

void MainWindow::sqlDrop()
{
    int button = QMessageBox::critical(this, "Confirm Drop",
                                       "Are you sure you wish to drop the table?",
                                       QMessageBox::Yes | QMessageBox::No);

    if(button == QMessageBox::Yes)
    {
        statusLabel->setText("Table dropped");
        model->setQuery("DROP TABLE grades");
        ui->tableView->setModel(model);
    }
    else
    {
        statusLabel->setText("DROP cancelled");
    }
}

void MainWindow::sqlShowAll()
{
    model->setQuery("SELECT * FROM grades");
    ui->tableView->setModel(model);
}
