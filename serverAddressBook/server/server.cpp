#include "server.h"

Server::Server(){
    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::Any);
    qDebug() << "Server started on port: " << m_socket->localPort();
}

Server::~Server(){}

void Server::send(const QByteArray& bytearray, const Client& client)
{
    m_socket->writeDatagram(bytearray, client.getAddress(), client.getPort());
}

void Server::receive()
{
    connect(m_socket, &QUdpSocket::readyRead, this, &Server::receiveData);
}

void Server::receiveData()
{
    QByteArray replyData;
    QHostAddress address;
    int port = 0;
    while (m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        replyData = datagram.data();
        port = datagram.senderPort();
        address = datagram.senderAddress();
    }
    emit receivedData(Client(port, address, replyData));
}
