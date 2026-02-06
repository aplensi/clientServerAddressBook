#include "changerequestcontroller.h"

ChangeRequestController::ChangeRequestController(ChangeRecordUseCase &usecase) : m_usecase(usecase){}

QJsonObject ChangeRequestController::handleRequest(const QJsonObject &body)
{
    m_usecase.change(Person(body["Id"].toInt(), body["Name"].toString(), body["Addres"].toString(), body["Phone"].toString()));
    QJsonObject obj;
    obj["Command"] = "Success";
    return obj;
}
