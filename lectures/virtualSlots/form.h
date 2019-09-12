#ifndef FORM_H
#define FORM_H
#include <QWidget>

namespace Ui
{
    class Form;
}

const int MODULUS = 4;
class Form : public QWidget
{
    Q_OBJECT
public:
    explicit Form(QWidget *parent = 0);
    ~Form();
private:
    Ui::Form *ui;
private slots:
    void processSpin();
signals:
    void updateStatus(QString);
};

#endif // FORM_H
