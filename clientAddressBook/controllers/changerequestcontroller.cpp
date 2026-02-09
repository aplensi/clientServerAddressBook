#include "changerequestcontroller.h"

ChangeRequestController::ChangeRequestController(GetDataUseCase &getData, PersonModel &model)
    : m_getData(getData), m_model(model){}

void ChangeRequestController::sendRequest(const int id, const QString& name, const QString& address, const QString& phone)
{
    QJsonObject obj;
    obj["Command"] = "Change";
    obj["Id"] = id;
    obj["Name"] = name;
    obj["Address"] = address;
    obj["Phone"] = phone;
    m_getData.pushData(obj);
}

void ChangeRequestController::setAnswer(const Request &request)
{
    QJsonObject obj = request.getBody();
    m_model.change(obj["Id"].toInt(), obj["Name"].toString(), obj["Address"].toString(), obj["Phone"].toString());
}
