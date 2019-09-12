#ifndef UDPLABEL_H
#define UDPLABEL_H

#include <QLabel>
#include <QUdpSocket>

namespace Ui {
class UDPLabel;
}

class UDPLabel : public QLabel
{
    Q_OBJECT

public:
    UDPLabel(QString msg);
    ~UDPLabel();

private:
    QUdpSocket *myUDPSocket;
    Ui::UDPLabel *ui;

private slots:
    void processPendingDatagrams();
};

#endif // UDPLABEL_H
