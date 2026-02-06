#ifndef QUERY_H
#define QUERY_H

#include "person.h"
#include <QHostAddress>
#include <QJsonObject>
#include <QtCore>

class Request
{
    uint16_t m_port;
    QHostAddress m_address;
    QString m_command;
    QJsonObject m_body;
public:
    Request(const uint16_t& port, const QHostAddress& address, const QString& command, const QJsonObject& body);
    uint16_t getPort() const;
    QHostAddress getAddress() const;
    QString getCommand() const;
    QJsonObject getBody() const;

};

#endif // QUERY_H
