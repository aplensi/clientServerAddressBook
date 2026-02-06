#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <QJsonObject>

class IController
{
public:
    virtual ~IController() = default;
    virtual QJsonObject handleRequest(const QJsonObject& body) = 0;
};

#endif // ICONTROLLER_H
