#include "client.h"

Client::Client(int port, QHostAddress address, QByteArray dataArray) : m_port(port), m_address(address), m_dataArray(dataArray){}

int Client::getPort() const
{
    return m_port;
}

QHostAddress Client::getAddress() const
{
    return m_address;
}

QByteArray Client::getDataArray() const
{
    return m_dataArray;
}

void Client::setDataArray(QByteArray dataArray)
{
    m_dataArray = dataArray;
}
