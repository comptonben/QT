#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    status = new QLabel("Ready");
    statusBar()->addWidget(status);

    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadFile);

    ui->filteredEdit->installEventFilter(this);

    QIntValidator *iv = new QIntValidator(0, 99, ui->lineEdit);
    ui->lineEdit->setValidator(iv);

    connect(ui->spawnButton, &QPushButton::clicked, this, &MainWindow::spawnButton);
    connect(ui->closeAllButton, &QPushButton::clicked, ui->lineEdit, &QLineEdit::clear);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFile()
{
    QString filename;
    QStringList options;
    filename = ui->fileNameEdit->text();
    status->setText(filename);

    disconnect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::loadFile);
    ui->fileNameEdit->clear();

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
            action = new QAction(temp, this);
            ui->mainToolBar->addAction(action);
            connect(action, &QAction::triggered, this, &MainWindow::actionTriggered);
        }
    }
    someFile.close();
}

void MainWindow::actionTriggered()
{
    qDebug() << "Action Triggerd";
}

void MainWindow::mousePressEvent(QMouseEvent *me)
{
    if(me && me->button() == Qt::RightButton)
    {
        count++;
        status->setNum(count);
        qDebug() << me->pos();
    }
    QMainWindow::mousePressEvent(me);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->filteredEdit)
    {
        if(e && e->type() == QEvent::KeyPress)
        {
            QKeyEvent *ke = static_cast<QKeyEvent*>(e);

            if(ke->key() == Qt::Key_PageDown)
            {
                status->setText("Page Down");
            }
            else if(ke->key() == Qt::Key_PageUp)
            {
                status->setText("Page Up");
            }
        }
    }
    return QMainWindow::eventFilter(obj, e);
}

void MainWindow::spawnButton()
{
    int popups = ui->lineEdit->text().toInt();

    for(int i = 0; i < popups; i++)
    {
        dialog = new QDialog();
        QHBoxLayout *layout = new QHBoxLayout();
        QLabel *dialogLabel = new QLabel("Dialog " + ui->lineEdit->text());
        dialogLabel->setFrameShape(QFrame::Panel);
        QLabel *xLabel = new QLabel();
        xLabel->setNum(i);
        xLabel->setFrameShape(QFrame::Panel);

        dialog->setLayout(layout);
        layout->addWidget(dialogLabel);
        layout->addWidget(xLabel);

        connect(ui->closeAllButton, &QPushButton::clicked, dialog, &QDialog::accept);

        dialog->show();
    }
    ui->lineEdit->clear();
}
