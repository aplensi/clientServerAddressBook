#include "request.h"

Request::Request(const QString &command, const QJsonObject &body)
    : m_command(command), m_body(body){}

QString Request::getCommand() const
{
    return m_command;
}

QJsonObject Request::getBody() const
{
    return m_body;
}
