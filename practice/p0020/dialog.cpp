#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;

    mainLayout = new QVBoxLayout(this);

    buttonLayout = new QHBoxLayout;
    submitButton = new QPushButton("Submit");
    quitButton = new QPushButton("Quit");
    buttonLayout->addWidget(submitButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(quitButton);
    connect(submitButton, &QPushButton::clicked, this, &Dialog::SubmitQuery);
    connect(quitButton, &QPushButton::clicked, this, &Dialog::ShutDownGracefully);

    statusLayout = new QHBoxLayout;
    label = new QLabel("Current Balance is $");
    balanceLabel = new QLabel("25");
    statusLayout->addStretch();
    statusLayout->addWidget(label);
    statusLayout->addWidget(balanceLabel);
    statusLayout->addStretch();

    editLayout = new QHBoxLayout;
    QGroupBox* dateBox = new QGroupBox("Transaction Date");
    dateEdit = new QDateEdit;
    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(dateEdit);
    dateBox->setLayout(vbox);

    QGroupBox *typeBox = new QGroupBox("Transaction Type");
    radio1 = new QRadioButton("Deposit");
    radio2 = new QRadioButton("Withdrawal");
    radio1->setChecked(true);
    QVBoxLayout *vbox2 = new QVBoxLayout;
    vbox2->addWidget(radio1);
    vbox2->addWidget(radio2);
    vbox2->addStretch(1);
    typeBox->setLayout(vbox2);

    QGroupBox* descBox = new QGroupBox("Description");
    descEdit = new QLineEdit;
    QVBoxLayout* vbox3 = new QVBoxLayout;
    vbox3->addWidget(descEdit);
    descBox->setLayout(vbox3);

    QGroupBox* amountBox = new QGroupBox("Amount");
    amountEdit = new QLineEdit;
    QRegExpValidator* validator = new QRegExpValidator(QRegExp("[0-9]{1,10}"));
    amountEdit->setValidator(validator);
    QVBoxLayout* vbox4 = new QVBoxLayout;
    vbox4->addWidget(amountEdit);
    amountBox->setLayout(vbox4);

    editLayout->addWidget(dateBox);
    editLayout->addStretch();
    editLayout->addWidget(typeBox);
    editLayout->addStretch();
    editLayout->addWidget(descBox);
    editLayout->addStretch();
    editLayout->addWidget(amountBox);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("register.db");

    if(!db.open())
    {
        qDebug() << db.lastError();
        qDebug() <<"Error: Unable to connect";
        return;
    }

    QString s = "CREATE TABLE register (transaction DATE, type TEXT CHECK( type IN ('deposit','withdrawal')), description TEXT, amount INT CHECK((type='deposit' AND amount > 0) OR (type='withdrawal' AND amount < 0)))";

    QSqlQuery q;
    q.exec(s);
    q.exec("INSERT INTO register VALUES('2000-01-01', 'deposit', 'Minimum Opening Deposit', 25)");

    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM register");

    view = new QTableView;
    view->setModel(model);

    mainLayout->addWidget(view);
    mainLayout->addStretch();
    mainLayout->addLayout(statusLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);
}

void Dialog::ShutDownGracefully()
{
    db.close();
    this->accept();
}

void Dialog::SubmitQuery()
{
    QSqlQuery q;
    QDate d;
    QString s;

    if((amountEdit->text() == "") || (descEdit->text() == ""))
        return;

    s = "INSERT INTO register VALUES(";
    d = dateEdit->date();
    s = s + "'" + d.toString("yyyy-MM-dd") + "', ";

    if(radio1->isChecked())
    {
        s = s + "'deposit', '";
        s = s + descEdit->text() + "', " + amountEdit->text() + ")";
    }
    else
    {
        s = s + "'withdrawal', '";
        s = s + descEdit->text() + "', -" + amountEdit->text() + ")";
    }

    q.exec(s);

    model->setQuery("SELECT * FROM register");
    view->setModel(model);

    q.exec("SELECT SUM(amount) FROM register");
    q.next();
    balanceLabel->setText(q.value(0).toString());

    descEdit->clear();
    amountEdit->clear();
}
