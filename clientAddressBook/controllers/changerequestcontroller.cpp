#include "changerequestcontroller.h"

ChangeRequestController::ChangeRequestController(GetDataUseCase &getData, PersonModel &model)
    : m_getData(getData), m_model(model){}

void ChangeRequestController::sendRequest(const Person &person)
{
    QJsonObject obj;
    obj["Command"] = "Change";
    obj["Id"] = person.id();
    obj["Name"] = person.name();
    obj["Address"] = person.address();
    obj["Phone"] = person.phone();
    m_getData.pushData(obj);
}

void ChangeRequestController::setAnswer(const Request &request)
{
    QJsonObject obj = request.getBody();
    m_model.change(obj["Id"].toInt(), obj["Name"].toString(), obj["Address"].toString(), obj["Phone"].toString());
}
