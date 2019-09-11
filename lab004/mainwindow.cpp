#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QEvent>
#include <QKeyEvent>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = new QLabel("0");
    statusBar()->addWidget(status);

    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *e)
{
    if(e && e->type() == QEvent::KeyPress)
    {
        QKeyEvent * ke = static_cast<QKeyEvent*>(e);

        if(ke->key() == Qt::Key_Escape)
        {
            qDebug() << "Escape";
        }
    }

    return QMainWindow::event(e);
}

void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    if(ke && ke->key() == Qt::Key_Escape)
    {
        int count = status->text().toInt();
        count++;
        status->setNum(count);
    }
    QMainWindow::keyPressEvent(ke);
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
    else if(!someFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error -- unable to open file for input";
    }
    else
    {
        qDebug() << "File opened for input successfully";
        QTextStream tempStream(&someFile);
        QString temp;
        while(!tempStream.atEnd())
        {
            temp = tempStream.readLine();
            options.append(temp);
            qDebug() << temp;
        }
    }
    someFile.close();

    ui->comboBox->addItems(options);
}
