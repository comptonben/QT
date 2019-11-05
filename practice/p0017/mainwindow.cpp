#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadImage = new QAction("Load Image", this);
    connect(loadImage, &QAction::triggered, this, &MainWindow::loadLabelImage);
    loadImage->setShortcuts(QKeySequence::Open);

    menu = menuBar()->addMenu("File");
    menu->addAction(loadImage);

    statusLabel = new QLabel("Ready");
    statusBar()->addWidget(statusLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadLabelImage()
{
    qDebug() << "Loading image now";

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("Images (*.png *.jpg)"));

    QFile imageFile(fileName);

    if(!imageFile.exists())
    {
        qDebug() << "Error -- file does not exist";
        return;
    }
    else if(!imageFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error -- unable to open file for input";
        return;
    }
    else
    {
        qDebug() << "File opened for input";
    }

    statusLabel->setText(fileName);

    QByteArray ba = imageFile.readAll();
    QPixmap pm;
    pm.loadFromData(ba);
    ui->imageLabel->setPixmap(pm);

    imageFile.close();
}
