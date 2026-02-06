#ifndef SERVER_H
#define SERVER_H

#include "../../commonFiles/Entities/request.h"
#include "../controller/icontroller.h"
#include <QObject>
#include <QNetworkDatagram>
#include <QUdpSocket>

class Server : public QObject
{
    Q_OBJECT
    QUdpSocket* m_socket;
    QHash<QString, IController*> m_controllers;

    void defineRequest(const Request& request);
    void receiveData();
public:
    Server();
    ~Server();
    void send(const QJsonObject& response, const QHostAddress address, const int port);
    void receive();

    void setControllers(const QString &key, IController* controller);
};

#endif // SERVER_H
