#ifndef CLIENT_H
#define CLIENT_H

#include "iclient.h"
#include <QObject>
#include <QNetworkDatagram>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUdpSocket>
#include <QTimer>

class Client : public IClient
{
    QUdpSocket* m_socket;
    QTimer* m_timer;
    QHostAddress& m_serverAddress;
    int m_serverPort;
    QJsonObject m_lastResponse;

    void receiveData();
    void resend();
public:
    Client(QHostAddress& address, int port);
    ~Client();
    void send(const QJsonObject& response);
};

#endif // CLIENT_H
