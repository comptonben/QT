#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->quitButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->enButton, &QPushButton::clicked, this, &Dialog::enqueue);
    connect(ui->deButton, &QPushButton::clicked, this, &Dialog::dequeue);
    connect(ui->frontButton, &QPushButton::clicked, this, &Dialog::front);
    connect(ui->rearButton, &QPushButton::clicked, this, &Dialog::rear);
    connect(ui->sizeButton, &QPushButton::clicked, this, &Dialog::size);
    connect(ui->viewButton, &QPushButton::clicked, this, &Dialog::view);
    connect(ui->clearButton, &QPushButton::clicked, this, &Dialog::clear);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::enqueue()
{
    auto temp = ui->lineEdit->text();
    ui->lineEdit->clear();

    bool ok;
    temp.toInt(&ok, 10);
    if(ok)
    {
        q.enqueue(temp);
    }
}

void Dialog::dequeue()
{
    QString temp = "Dequeued = ";
    if(!q.empty())
    {
        temp.append(q.dequeue());
    }
    else
    {
        temp.append("Empty");
    }
    showResult(temp);
}

void Dialog::front()
{
    QString temp = "Front = ";
    if(!q.empty())
    {
        temp.append(q.first());
    }
    else
    {
        temp.append("Empty");
    }
    showResult(temp);
}

void Dialog::rear()
{
    QString temp = "Rear = ";
    if(!q.empty())
    {
        temp.append(q.last());
    }
    else
    {
        temp.append("Empty");
    }
    showResult(temp);
}

void Dialog::size()
{
    QString temp = "Queue size = ";
    temp.append(QString::number(q.size()));
    showResult(temp);
}

void Dialog::view()
{
    QString temp = "Front [ ";
    auto n = q.size();

    for(int i = 0; i < n; i++)
    {
        temp.append(q[i]);
        temp.append(" ");
    }
    temp.append("] Rear");
    showResult(temp);
}

void Dialog::clear()
{
    q.clear();
}

void Dialog::showResult(QString &r)
{
    QDialog* dialog = new QDialog;
    QLayout* layout = new QVBoxLayout;
    QPushButton* button = new QPushButton("Close");
    QLabel* label = new QLabel(r);

    dialog->setLayout(layout);
    layout->addWidget(label);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->exec();
}
