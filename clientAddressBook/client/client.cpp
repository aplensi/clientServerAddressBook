#include "client.h"

Client::Client(QHostAddress &address, int port)
    : m_serverAddress(address), m_serverPort(port) {
    m_socket = new QUdpSocket(this);
    m_socket->bind(QHostAddress::Any);
    connect(m_socket, &QUdpSocket::readyRead, this, &Client::receiveData);
    m_timer = new QTimer;
    m_timer->setInterval(2000);
    connect(m_timer, &QTimer::timeout, this, &Client::resend);
}

Client::~Client()
{
    m_socket->deleteLater();
    m_timer->deleteLater();
}

void Client::send(const QJsonObject &response)
{
    m_lastResponse = response;
    m_socket->writeDatagram(QJsonDocument(m_lastResponse).toJson(QJsonDocument::Compact), m_serverAddress, m_serverPort);
    m_timer->start();
}

void Client::receiveData()
{
    m_timer->stop();
    QByteArray replyData;
    QJsonObject obj;

    while (m_socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = m_socket->receiveDatagram();
        replyData = datagram.data();
    }

    obj = QJsonDocument::fromJson(replyData).object();

    qDebug() << replyData;

    emit dataReceived(Request(obj["Command"].toString(), obj));
}

void Client::resend()
{
    m_socket->writeDatagram(QJsonDocument(m_lastResponse).toJson(QJsonDocument::Compact), m_serverAddress, m_serverPort);
    m_timer->start();
}
