#ifndef SERVER_H
#define SERVER_H

#include "entity/client.h"
#include <QObject>
#include <QNetworkDatagram>
#include <QUdpSocket>

class Server : public QObject
{
    Q_OBJECT
    QUdpSocket* m_socket;
public:
    Server();
    ~Server();
    void send(const QByteArray& bytearray, const Client& client);
    void receive();
signals:
    void receivedData(Client client);
public slots:
    void receiveData();
};

#endif // SERVER_H
