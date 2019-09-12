#include <QCoreApplication>
#include <QFile>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile someFile("../fileExample1/sample.txt");
    if(!someFile.exists())
    {
        qDebug() << "Error -- file does not exist";
    }
    else if (!someFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error -- unable to open file for input";
    }
    else
    {
        qDebug() << "File opened for input successfully";
    }
    someFile.close();

    return a.exec();
}
