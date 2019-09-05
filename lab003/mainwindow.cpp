#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->clearButton, &QPushButton::clicked,
            this, &MainWindow::clearNumber);
    connect(ui->dialButton, &QPushButton::clicked,
            this, &MainWindow::dialNumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearNumber()
{
    ui->areaCodeLineEdit->clear();
    ui->firstThreeLineEdit->clear();
    ui->lastFourLineEdit->clear();
}

void MainWindow::dialNumber()
{

}
