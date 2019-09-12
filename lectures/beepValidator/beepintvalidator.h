#ifndef BEEPINTVALIDATOR_H
#define BEEPINTVALIDATOR_H

#include <QObject>
#include <QIntValidator>
#include <QApplication>

class BeepIntValidator : public QIntValidator
{
public:
    BeepIntValidator(QObject *parent = 0);
    BeepIntValidator(int minimum, int maximum, QObject *parent);
    QValidator::State validate(QString &input, int &pos) const;
};

#endif // BEEPINTVALIDATOR_H
