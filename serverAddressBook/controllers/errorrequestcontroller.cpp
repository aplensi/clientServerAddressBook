#include "errorrequestcontroller.h"

QJsonObject ErrorRequestController::handleRequest(const QJsonObject &body)
{
    QJsonObject obj;
    obj["Command"] = "Error";
    return obj;
}
