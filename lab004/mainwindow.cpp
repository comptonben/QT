#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFile()
{
    QString filename;
    QStringList options;
    filename = ui->fileLineEdit->text();

    QFile someFile(filename);
    if(!someFile.exists())
    {
        qDebug() << "Error -- file does not exist";
    }
    else if(!someFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error -- unable to open file for input";
    }
    else
    {
        qDebug() << "File opened for input successfully";
    }

    while(!someFile.atEnd())
    {
        QString temp = someFile.readLine();
        options.append(temp);
        qDebug() << temp;
    }

    ui->comboBox->addItems(options);

    someFile.close();
}
