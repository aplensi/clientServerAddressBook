#include "server.h"

Server::Server(){
    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::Any, 25565);
    qDebug() << "Server started on port: " << m_socket->localPort();
}

Server::~Server(){
    qDeleteAll(m_controllers);
    m_controllers.clear();
    m_socket->deleteLater();
}

void Server::send(const QJsonObject& response, const QHostAddress address, const int port)
{
    m_socket->writeDatagram(QJsonDocument(response).toJson(QJsonDocument::Compact), address, port);
}

void Server::receive()
{
    connect(m_socket, &QUdpSocket::readyRead, this, &Server::receiveData);
}

void Server::setControllers(const QString &key, IController *controller)
{
    m_controllers[key] = controller;
}

void Server::defineRequest(const Request &request)
{
    if(m_controllers.contains(request.getCommand())){
        if(randomSend(50))
            send(m_controllers[request.getCommand()]->handleRequest(request.getBody()), request.getAddress(), request.getPort());
    }else{
        send(m_controllers["Error"]->handleRequest(QJsonObject()), request.getAddress(), request.getPort());
    }
}

void Server::receiveData()
{
    QByteArray replyData;
    QJsonObject obj;
    QHostAddress address;
    int port = 0;

    while (m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        replyData = datagram.data();
        port = datagram.senderPort();
        address = datagram.senderAddress();
    }

    obj = QJsonDocument::fromJson(replyData).object();
    if(!obj.contains("Command")){
        qDebug() << "Broken package: " << replyData << " | "
                 << address << ":" << port;
        return;
    }

    qDebug() << "Command: " << obj["Command"].toString() << " | Body: " << replyData << " | "
             << address << ":" << port;
    defineRequest(Request(port, address, obj["Command"].toString(), obj));
}

bool Server::randomSend(const int chance)
{
    int number = QRandomGenerator::global()->bounded(0, 100);
    if(number <= chance)
        return true;
    return false;
}
