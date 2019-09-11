#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Ready");

    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearNumber);
    connect(ui->dialButton, &QPushButton::clicked, this, &MainWindow::dialNumber);

    QIntValidator* acValidator = new QIntValidator(0,999, ui->areaCode);
    ui->areaCode->setValidator(acValidator);

    QRegularExpressionValidator* threeDigitValidator = new QRegularExpressionValidator(QRegularExpression("[0-9]{3}"), ui->prefix);
    ui->prefix->setValidator(threeDigitValidator);

    QRegularExpressionValidator* fourDigitValidator = new QRegularExpressionValidator(QRegularExpression("[0-9]{3}"), ui->subscriber);
    ui->prefix->setValidator(fourDigitValidator);

    QRegularExpression regex("[A-Z]{1}[a-z]{1}[A-Z]{1}[a-z]{1}[A-Z]{1}[a-z]{1}");
    QRegularExpressionValidator* lineEditValidator = new QRegularExpressionValidator(regex, ui->lineEdit);
    ui->lineEdit->setValidator(lineEditValidator);

    // Configure actions
    action1 = new QAction(QIcon(":/images/red.png"), "Default Area Code", this);
    action2 = new QAction(QIcon(":/images/green.png"), "Default Prefix", this);
    action3 = new QAction(QIcon(":/images/blue.png"), "Default Subscriber", this);
    actionMenu = menuBar()->addMenu("&Actions");
    actionMenu->addAction(action1);
    actionMenu->addSeparator();
    actionMenu->addAction(action2);
    actionMenu->addSeparator();
    actionMenu->addAction(action3);

    ui->mainToolBar->addAction(action1);
    ui->mainToolBar->addAction(action2);
    ui->mainToolBar->addAction(action3);

    connect(action1, &QAction::triggered, this, &MainWindow::defaultAreaCode);
    connect(action2, &QAction::triggered, this, &MainWindow::defaultPrefix);
    connect(action3, &QAction::triggered, this, &MainWindow::defaultSubscriber);

    // Add label to status bar
    status = new QLabel("Ready");
    ui->statusBar->addWidget(status);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearNumber()
{
    ui->areaCode->clear();
    ui->prefix->clear();
    ui->subscriber->clear();
}

void MainWindow::dialNumber()
{
    QString temp = ui->areaCode->text() + "-" + ui->prefix->text() + "-" + ui->subscriber->text();
    status->setText(temp);
}

void MainWindow::defaultAreaCode()
{
    ui->areaCode->setText("999");
}

void MainWindow::defaultPrefix()
{
    ui->prefix->setText("999");
}

void MainWindow::defaultSubscriber()
{
    ui->subscriber->setText("9999");
}
