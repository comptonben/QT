#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addStuff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addStuff()
{
    auto temp = ui->lineEdit->text();

}
