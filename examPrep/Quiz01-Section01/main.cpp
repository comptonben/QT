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
int lSliderValue;
int rSliderValue;

void SaveOriginalInitialization(Dialog& w);
void CheckInitialization(Dialog& w);
void CheckLeftSlider2LeftLabel(Dialog& w);
void CheckRightSlider2RightLabel(Dialog& w);
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
    CheckLeftSlider2LeftLabel(w);
    qDebug() << " ";
    CheckRightSlider2RightLabel(w);
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

    /* Alter leftSlider and test to see that rightSlider adjusts automatically to sum to 5 */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->leftSlider->setValue(k);
        if ( w.ui->leftSlider->value() + w.ui->rightSlider->value() != 5)
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
    s.append("value(leftSlider)^ + value(rightSlider) == 5");
    qDebug() << s;

    /* Alter rightSlider and test to see that leftSlider adjusts automatically to sum to 5 */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->rightSlider->setValue(k);
        if ( w.ui->leftSlider->value() + w.ui->rightSlider->value() != 5)
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
    s.append("value(leftSlider) + value(rightSlider)^ == 5");
    qDebug() << s;

    qDebug() << "*********  END  Slider Sum Check *******";
    qDebug() << "******************************************************";

}

void CheckRightSlider2RightLabel(Dialog& w)
{
    qDebug() << "*******************************************************";
    qDebug() << "********* BEGIN Right SLider 2 Right Label Check *******";

    QString s;
    bool passed = true;

    /* Alter rightSlider and test to see that rightLabel adjusts automatically to match */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->rightSlider->setValue(k);
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
    s.append("value(rightLabel) <- value(rightSlider)^");
    qDebug() << s;

    qDebug() << "*********  END  Right Slider 2 Right Label Check *******";
    qDebug() << "******************************************************";

}


void CheckLeftSlider2LeftLabel(Dialog& w)
{
    qDebug() << "*******************************************************";
    qDebug() << "********* BEGIN Left SLider 2 Left Label Check *******";

    QString s;
    bool passed = true;

    /* Alter leftSlider and test to see that leftLabel adjusts automatically to match */
    for(int k = 0; k <= 5; k++)
    {
        w.ui->leftSlider->setValue(k);
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
    s.append("value(leftLabel) <- value(leftSlider)^");
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

    if ( IntWidgetCheck(QString("leftSlider->value()"), 0, w.ui->leftSlider->value()) )
    {
        score = score + delta;
    }

    if ( IntWidgetCheck(QString("rightSlider->value()"), 5, w.ui->rightSlider->value()) )
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
    lSliderValue = w.ui->leftSlider->value();
    rSliderValue = w.ui->rightSlider->value();

    qDebug() << "Left Label = " << lLabelText;
    qDebug() << "Left Slider = " << lSliderValue;
    qDebug() << "Right Label = " << rLabelText;
    qDebug() << "Right Slider = " << rSliderValue;

    qDebug() << "*********  END  SaveOriginalInitialization  *******";
    qDebug() << "********************************************";

}

void RestoreOriginalInitialization(Dialog& w)
{
    qDebug() << "********************************************";
    qDebug() << "********* BEGIN RestoreOriginalInitialization  *******";

    w.ui->leftLabel->setText(lLabelText);
    w.ui->rightLabel->setText(rLabelText);
    w.ui->leftSlider->setValue(lSliderValue);
    w.ui->rightSlider->setValue(rSliderValue);

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
