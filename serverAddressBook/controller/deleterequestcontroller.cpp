#include "deleterequestcontroller.h"

DeleteRequestController::DeleteRequestController(DeleteRecordUseCase &usecase) : m_usecase(usecase){}

QJsonObject DeleteRequestController::handleRequest(const QJsonObject &body)
{
    m_usecase.remove(body["Id"].toInt());
    QJsonObject obj;
    obj["Command"] = "Success";
    return obj;
}

