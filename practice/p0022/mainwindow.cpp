#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QFileDialog>
#include <QPainter>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->overlayButton, &QPushButton::clicked, this, &MainWindow::newLabelImage);
    connect(ui->blackRadioButton, &QPushButton::clicked, this, &MainWindow::backgroundChanged);
    connect(ui->grayRadioButton, &QPushButton::clicked, this, &MainWindow::backgroundChanged);
    connect(ui->whiteRadioButton, &QPushButton::clicked, this, &MainWindow::backgroundChanged);
    connect(ui->redRadioButton, &QPushButton::clicked, this, &MainWindow::foregroundChanged);
    connect(ui->greenRadioButton, &QPushButton::clicked, this, &MainWindow::foregroundChanged);
    connect(ui->blueRadioButton, &QPushButton::clicked, this, &MainWindow::foregroundChanged);

    loadImage = new QAction("Load Image", this);
    connect(loadImage, &QAction::triggered, this, &MainWindow::loadLabelImage);
    loadImage->setShortcut(QKeySequence::Open);

    saveImage = new QAction("Save Image", this);
    connect(saveImage, &QAction::triggered, this, &MainWindow::saveLabelImage);
    saveImage->setShortcut(QKeySequence::Save);

    quit = new QAction("Quit Image", this);
    connect(quit, &QAction::triggered, this, &MainWindow::close);
    quit->setShortcut(QKeySequence::Quit);

    menu = menuBar()->addMenu("File");
    menu->addAction(loadImage);
    menu->addAction(saveImage);
    menu->addSeparator();
    menu->addAction(quit);

    statusLabel = new QLabel(" Ready ");
    statusBar()->addWidget(statusLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::backgroundChanged()
{
    qDebug() << "Background Changed";

    if(ui->blackRadioButton->isChecked())
        backgroundColor = Qt::black;
    else if(ui->grayRadioButton->isChecked())
        backgroundColor = Qt::gray;
    else
        backgroundColor = Qt::white;
}

void MainWindow::foregroundChanged()
{
    qDebug() << "Foreground Changed";

    if(ui->redRadioButton->isChecked())
        foregroundColor = Qt::red;
    else if(ui->greenRadioButton->isChecked())
        foregroundColor = Qt::green;
    else
        foregroundColor = Qt::blue;
}

void MainWindow::newLabelImage()
{
    QPixmap* pm = new QPixmap(400, 300);
    pm->fill(backgroundColor);
    QPainter p(pm);
    p.setPen(foregroundColor);
    p.setFont(QFont("Helvetica", 20, QFont::Bold));
    QPoint tp(40, 40);
    p.drawText(tp, ui->overlayEdit->text());
    ui->imageLabel->setPixmap(*pm);
}

void MainWindow::saveLabelImage()
{
    qDebug() << "Saving image now";

    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "/", tr("Images (*.png *.jpg)"));
    QFile imageFile(filename);

    if(imageFile.exists())
    {
        qDebug() << "Error -- file already exists, try again";
        return;
    }
    else if(!imageFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error -- unable to open file for output";
        return;
    }
    else
    {
        qDebug() << "FIle opened for output";
    }

    statusLabel->setText(filename);
    if(ui->imageLabel->pixmap()->save(filename))
        qDebug() << "Image saved to file: " << filename;
    else
        qDebug() << "Error -- unable to save image to file";

    imageFile.close();
}

void MainWindow::loadLabelImage()
{
    qDebug() << "Loading image now";

    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("Images (*.png *.jpg)"));
    QFile imageFile(filename);
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

    statusLabel->setText(filename);

    QByteArray ba = imageFile.readAll();
    QPixmap pm;
    pm.loadFromData(ba);
    ui->imageLabel->setPixmap(pm);

    imageFile.close();
}
