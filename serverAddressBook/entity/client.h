#ifndef CLIENT_H
#define CLIENT_H

#include <QByteArray>
#include <QHostAddress>

class Client
{
    int m_port;
    QHostAddress m_address;
    QByteArray m_dataArray;
public:
    Client(int port, QHostAddress address, QByteArray dataArray);
    int getPort() const;
    QHostAddress getAddress() const;
    QByteArray getDataArray() const;
    void setDataArray(QByteArray dataArray);
};

#endif // CLIENT_H
