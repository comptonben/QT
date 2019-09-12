#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    form = new Form(this);
    setCentralWidget(form);
    form->setBaseSize(ui->centralWidget->frameSize());

    helpAction = new QAction(QIcon(":/images/help.png"), "Help", this);
    helpAction->setShortcuts(QKeySequence::AddTab);
    aboutQtAction = new QAction("About Qt", this);
    quitAction = new QAction("Quit", this);

    connect(helpAction, SIGNAL(triggered()), this, SLOT(showHelp()));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    optionsMenu = menuBar()->addMenu("&Options");
    optionsMenu->addAction(helpAction);
    optionsMenu->addAction(aboutQtAction);
    optionsMenu->addSeparator();
    optionsMenu->addAction(quitAction);

    toolBar = addToolBar("Options");
    toolBar->addAction(helpAction);
    toolBar->setIconSize(QSize(25,25));

    statusLabel = new QLabel(" Ready ");
    statusBar()->addWidget(statusLabel);

    connect(form, SIGNAL(updateStatus(QString)), statusLabel, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showHelp()
{
    int status = QMessageBox::information(this, "Help",
                "Press spin button to cycle wheels.\n"
                "Exact match of all three wheels wins.");
    qDebug() << "Help Actions = " << status;
}
