#ifndef SERVER_H
#define SERVER_H

#include "../../commonFiles/Entities/request.h"
#include "../controllers/icontroller.h"
#include <QRandomGenerator>
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
    bool randomSend(const int chance);
public:
    Server();
    ~Server();
    void send(const QJsonObject& response, const QHostAddress address, const int port);
    void receive();

    void setControllers(const QString &key, IController* controller);
};

#endif // SERVER_H
