#include "beepintvalidator.h"

BeepIntValidator::BeepIntValidator(QObject* parent) : QIntValidator(parent)
{

}

BeepIntValidator::BeepIntValidator(int minimum, int maximum, QObject* parent) : QIntValidator(minimum, maximum, parent)
{

}

QValidator::State BeepIntValidator::validate(QString &input, int &pos) const
{
    QValidator::State status = QIntValidator::validate(input, pos);

    if(status == QIntValidator::Invalid)
    {
        QApplication::beep();
    }

    return status;
}
