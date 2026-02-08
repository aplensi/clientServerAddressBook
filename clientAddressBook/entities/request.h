#ifndef REQUEST_H
#define REQUEST_H

#include <QString>
#include <QJsonObject>

class Request
{
    QString m_command;
    QJsonObject m_body;
public:
    Request(const QString& command, const QJsonObject& body);
    QString getCommand() const;
    QJsonObject getBody() const;

};

#endif // REQUEST_H
