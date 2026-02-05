#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include "../Entities/query.h"
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

class JsonParser
{
public:
    JsonParser();
    Query toQuery(const QByteArray& array);
    QByteArray toByteArray(const Query& query);
};

#endif // JSONCONTROLLER_H
