#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listView->setModel(itemModel);
    ui->tableView->setModel(itemModel);
    ui->treeView->setModel(itemModel);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addStuff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addStuff()
{
    auto temp = ui->lineEdit->text();
    ui->lineEdit->clear();
    itemModel->appendRow(new QStandardItem(temp));
}
