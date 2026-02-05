#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include "../Entities/request.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class JsonParser
{
public:
    JsonParser();
    Request toRequest(const QByteArray& array);
    QByteArray toByteArray(const Request& request);
};

#endif // JSONCONTROLLER_H
