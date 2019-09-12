#include <QCoreApplication>
#include <QFile>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile someFile("../fileTextStreams/sample.txt");
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
        QTextStream someStream(&someFile);
        QString someValue;
        while(!someStream.atEnd())
        {
            someStream >> someValue;
            qDebug() << someValue;
        }
        someFile.close();
    }


    return a.exec();
}
