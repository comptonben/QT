#include "memodialog.h"
#include "ui_memodialog.h"

MemoDialog::MemoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoDialog)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::accept);
}

MemoDialog::~MemoDialog()
{
    delete ui;
}
