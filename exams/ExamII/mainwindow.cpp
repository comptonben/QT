#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "togglelabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    status = new QLabel("Ready");
    ui->statusBar->addWidget(status);

    ui->filteredEdit->installEventFilter(this);
    // HINT: P02 - event filtering
    ui->filteredEdit->textCursor().insertText("1  ");

    QAction *load = new QAction("Load", this);
    QAction *save = new QAction("Save", this);
    QMenu *fileMenu = new QMenu("File", this);
    fileMenu->addAction(load);
    fileMenu->addAction(save);
    ui->menuBar->addMenu(fileMenu);

    connect(load, &QAction::triggered, this, &MainWindow::loadFile);
    connect(save, &QAction::triggered, this, &MainWindow::saveFile);

    ui->usernameEdit->setText("bc0045");
    connect(ui->spawnButton, &QPushButton::clicked, this, &MainWindow::spawnButton);

    connect(ui->applyButton, &QPushButton::clicked, this, &MainWindow::applyButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->filteredEdit)
    {
        if(e && e->type() == QEvent::KeyPress)
        {
            QKeyEvent *ke = static_cast<QKeyEvent*>(e);

            if(ke->key() == Qt::Key_Return || ke->key() == Qt::Key_Enter)
            {
                lineCount++;
                status->setNum(lineCount);
                ui->filteredEdit->textCursor().insertText("\r\n" + status->text() + "  ");
                return true;
            }
        }
    }
    return QMainWindow::eventFilter(obj, e);
}

void MainWindow::loadFile()
{
    QString filename;
    QStringList options;
    filename = ui->fileNameEdit->text();
    status->setText(filename);

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
        ui->filteredEdit->clear();
        ui->filteredEdit->textCursor().insertText("1  ");
        while(!tempStream.atEnd())
        {
            temp = tempStream.readLine();
            ui->filteredEdit->textCursor().insertText(temp);

        }
    }
    someFile.close();
}

void MainWindow::saveFile()
{
    QString filename;
    QStringList options;
    filename = ui->fileNameEdit->text();
    status->setText(filename);

    ui->fileNameEdit->clear();

    QFile someFile(filename);
    if(!someFile.exists())
    {

    }
    else if(!someFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {

    }
    else
    {

    }
    someFile.close();
}

void MainWindow::spawnButton()
{
    QDialog *popup = new QDialog();
    QHBoxLayout *layout = new QHBoxLayout();
    QLabel *label = new QLabel(ui->usernameEdit->text());
    ToggleLabel *tLabel = new ToggleLabel();
    layout->addWidget(label);
    layout->addWidget(tLabel);
    popup->setLayout(layout);

    connect(ui->closeButton, &QPushButton::clicked, popup, &QDialog::accept);

    if(ui->modalButton->isChecked())
    {
        popup->exec();
    }
    else {
        popup->show();
    }
}

void MainWindow::applyButton()
{
    QString regex = ui->regexEdit->text();
    ui->protectedEdit->clear();

    QRegularExpressionValidator *rv = new QRegularExpressionValidator(QRegularExpression(regex), ui->protectedEdit);
    ui->protectedEdit->setValidator(rv);
}
