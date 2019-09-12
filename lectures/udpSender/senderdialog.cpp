#include "senderdialog.h"
#include "ui_senderdialog.h"

SenderDialog::SenderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SenderDialog)
{
    ui->setupUi(this);

    label = new QLabel("Enter Message Here:");
    lineEdit = new QLineEdit;
    sendButton = new QPushButton("&Send");
    quitButton = new QPushButton("&Quit");
    mainLayout = new QVBoxLayout(this);
    editLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
    editLayout->addWidget(label);
    editLayout->addWidget(lineEdit);
    buttonLayout->addStretch();
    buttonLayout->addWidget(sendButton);
    buttonLayout->addWidget(quitButton);

    connect(sendButton, SIGNAL(clicked()), this, SLOT(writeMessage()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(accept()));

    // QT5
    // connect(sendButton, &QPushButton::clicked, this, &SenderDialog::writeMessage);
    // connect(quitButton, &QPushButton::clicked, this, &SenderDialog::writeMessage);

    sendSocket = new QUdpSocket;
}

SenderDialog::~SenderDialog()
{
    delete ui;
}

void SenderDialog::writeMessage()
{
    QByteArray datagram;

    QTextStream out(&datagram, QIODevice::WriteOnly);

    QString msg = lineEdit->text();
    lineEdit->setText("");

    out << msg << endl;

    sendSocket->writeDatagram(datagram, QHostAddress::LocalHost, 5678);
}
