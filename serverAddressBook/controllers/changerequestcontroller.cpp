#include "changerequestcontroller.h"

ChangeRequestController::ChangeRequestController(ChangeRecordUseCase &usecase) : m_usecase(usecase){}

QJsonObject ChangeRequestController::handleRequest(const QJsonObject &body)
{
    m_usecase.change(Person(body["Id"].toInt(), body["Name"].toString(), body["Address"].toString(), body["Phone"].toString()));
    QJsonObject obj;
    obj["Command"] = "Change";
    obj["Id"] = body["Id"].toInt();
    obj["Name"] = body["Name"].toString();
    obj["Address"] = body["Address"].toString();
    obj["Phone"] = body["Phone"].toString();
    return obj;
}
