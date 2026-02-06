#include "request.h"

Request::Request(const uint16_t &port, const QHostAddress &address, const QString &command, const QJsonObject &body)
    : m_port(port), m_address(address), m_command(command), m_body(body){}

uint16_t Request::getPort() const
{
    return m_port;
}

QHostAddress Request::getAddress() const
{
    return m_address;
}

QString Request::getCommand() const
{
    return m_command;
}

QJsonObject Request::getBody() const
{
    return m_body;
}
