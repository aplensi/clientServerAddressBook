#ifndef ERRORREQUESTCONTROLLER_H
#define ERRORREQUESTCONTROLLER_H

#include "icontroller.h"
#include <QJsonObject>

class ErrorRequestController : public IController
{
public:
    QJsonObject handleRequest(const QJsonObject& body) override;
};

#endif // ERRORREQUESTCONTROLLER_H
