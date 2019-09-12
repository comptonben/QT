// *********************************
// DO NOT MODIFY OR SUBMIT THIS FILE
// *********************************

#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>
#include <QtDebug>

/******************** BEGIN -- Test Harness Declarations ******************/

double score = 0.0;
const double delta = 0.25;
const double n = 8;

QString lLabelText;
QString rLabelText;
int lDialValue;
int rDialValue;

void SaveOriginalInitialization(Dialog& w);
void CheckInitialization(Dialog& w);
void CheckLeftDial2LeftLabel(Dialog& w);
void CheckRightDial2RightLabel(Dialog& w);
void CheckSliderSum(Dialog& w);
void RestoreOriginalInitialization(Dialog& w);
bool StringWidgetCheck(QString widgetName, QString correctWidgetValue, QString actualWidgetValue);
bool IntWidgetCheck(QString widgetName, int correctWidgetValue, int actualWidgetValue);

/********************   END -- Test Harness Declarations ******************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w;
    w.show();

    SaveOriginalInitialization(w);   // Save copy of original initialization

    CheckInitialization(w);
    qDebug() << " ";
    CheckLeftDial2LeftLabel(w);
    qDebug() << " ";
    CheckRightDial2RightLabel(w);
    qDebug() << " ";
    CheckSliderSum(w);

    qDebug() << "Total Score = " << score << " out of " << delta * n;

    RestoreOriginalInitialization(w);   // Restore original initialization

    return a.exec();
}

void CheckSliderSum(Dialog& w)
{
    qDebug() << "*******************************************************";
    qDebug() << "********* BEGIN Slider Sum Check *******";

    QString s;
    bool passed = true;

    /* Alter leftDial and test to see that rightDial adjusts automatically to sum to 5 */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->leftDial->setValue(k);
        if ( w.ui->leftDial->value() + w.ui->rightDial->value() != 5)
        {
            passed = false;
            break;
        }
    }
    if (passed)
    {
        s = "PASSED: ";
        score = score + delta;
    }
    else
    {
        s = "FAILED: ";
    }
    s.append("value(leftDial)^ + value(rightDial) == 5");
    qDebug() << s;

    /* Alter rightDial and test to see that leftDial adjusts automatically to sum to 5 */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->rightDial->setValue(k);
        if ( w.ui->leftDial->value() + w.ui->rightDial->value() != 5)
        {
            passed = false;
            break;
        }
    }
    if (passed)
    {
        s = "PASSED: ";
        score = score + delta;
    }
    else
    {
        s = "FAILED: ";
    }
    s.append("value(leftDial) + value(rightDial)^ == 5");
    qDebug() << s;

    qDebug() << "*********  END  Slider Sum Check *******";
    qDebug() << "******************************************************";

}

void CheckRightDial2RightLabel(Dialog& w)
{
    qDebug() << "*******************************************************";
    qDebug() << "********* BEGIN Right SLider 2 Right Label Check *******";

    QString s;
    bool passed = true;

    /* Alter rightDial and test to see that rightLabel adjusts automatically to match */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->rightDial->setValue(k);
        if (w.ui->rightLabel->text() != QString::number(k))
        {
            passed = false;
            break;
        }
    }
    if (passed)
    {
        s = "PASSED: ";
        score = score + delta;
    }
    else
    {
        s = "FAILED: ";
    }
    s.append("value(rightLabel) <- value(rightDial)^");
    qDebug() << s;

    qDebug() << "*********  END  Right Slider 2 Right Label Check *******";
    qDebug() << "******************************************************";

}


void CheckLeftDial2LeftLabel(Dialog& w)
{
    qDebug() << "*******************************************************";
    qDebug() << "********* BEGIN Left SLider 2 Left Label Check *******";

    QString s;
    bool passed = true;

    /* Alter leftDial and test to see that leftLabel adjusts automatically to match */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->leftDial->setValue(k);
        if (w.ui->leftLabel->text() != QString::number(k))
        {
            passed = false;
            break;
        }
    }
    if (passed)
    {
        s = "PASSED: ";
        score = score + delta;
    }
    else
    {
        s = "FAILED: ";
    }
    s.append("value(leftLabel) <- value(leftDial)^");
    qDebug() << s;

    qDebug() << "*********  END  Left Slider 2 Left Label Check *******";
    qDebug() << "******************************************************";

}


void CheckInitialization(Dialog& w)
{
    qDebug() << "********************************************";
    qDebug() << "********* BEGIN Initialization Check *******";

    QString s;


    if ( StringWidgetCheck(QString("leftLabel->text()"), QString("0"), w.ui->leftLabel->text()) )
    {
        score = score + delta;
    }

    if ( StringWidgetCheck(QString("rightLabel->text()"), QString("5"), w.ui->rightLabel->text()) )
    {
        score = score + delta;
    }

    if ( IntWidgetCheck(QString("leftDial->value()"), 0, w.ui->leftDial->value()) )
    {
        score = score + delta;
    }

    if ( IntWidgetCheck(QString("rightDial->value()"), 5, w.ui->rightDial->value()) )
    {
        score = score + delta;
    }

    qDebug() << "*********  END  Initialization Check *******";
    qDebug() << "********************************************";

}

void SaveOriginalInitialization(Dialog& w)
{
    qDebug() << "********************************************";
    qDebug() << "********* BEGIN SaveOriginalInitialization  *******";

    lLabelText = w.ui->leftLabel->text();
    rLabelText = w.ui->rightLabel->text();
    lDialValue = w.ui->leftDial->value();
    rDialValue = w.ui->rightDial->value();

    qDebug() << "Left Label = " << lLabelText;
    qDebug() << "Left Slider = " << lDialValue;
    qDebug() << "Right Label = " << rLabelText;
    qDebug() << "Right Slider = " << rDialValue;

    qDebug() << "*********  END  SaveOriginalInitialization  *******";
    qDebug() << "********************************************";

}

void RestoreOriginalInitialization(Dialog& w)
{
    qDebug() << "********************************************";
    qDebug() << "********* BEGIN RestoreOriginalInitialization  *******";

    w.ui->leftLabel->setText(lLabelText);
    w.ui->rightLabel->setText(rLabelText);
    w.ui->leftDial->setValue(lDialValue);
    w.ui->rightDial->setValue(rDialValue);

    qDebug() << "*********  END  RestoreOriginalInitialization  *******";
    qDebug() << "********************************************";

}

bool StringWidgetCheck(QString widgetName, QString correctWidgetValue, QString actualWidgetValue)
{
    bool temp;
    QString summary;

    if (actualWidgetValue == correctWidgetValue)
    {
        summary = "PASSED: ";
        temp = true;
    }
    else
    {
        summary = "FAILED: ";
        temp = false;
    }

    summary.append(widgetName);
    summary.append(" == ");
    summary.append(correctWidgetValue);

    qDebug() << summary;

    return temp;
}

bool IntWidgetCheck(QString widgetName, int correctWidgetValue, int actualWidgetValue)
{
    bool temp;
    QString summary;

    if (actualWidgetValue == correctWidgetValue)
    {
        summary = "PASSED: ";
        temp = true;
    }
    else
    {
        summary = "FAILED: ";
        temp = false;
    }

    summary.append(widgetName);
    summary.append(" == ");
    summary.append(QString().setNum(correctWidgetValue));

    qDebug() << summary;

    return temp;
}
