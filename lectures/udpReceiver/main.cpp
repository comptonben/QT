#include "udplabel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDPLabel myUDPLabel("***Ready to Receive***");
    myUDPLabel.show();

    return a.exec();
}
