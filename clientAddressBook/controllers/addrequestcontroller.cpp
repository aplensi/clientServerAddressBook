#include "addrequestcontroller.h"

AddRequestController::AddRequestController(GetDataUseCase &getData, PersonModel& model)
    : m_getData(getData), m_model(model){}

void AddRequestController::sendRequest(const QString& name, const QString& address, const QString& phone)
{
    QJsonObject obj;
    obj["Command"] = "Add";
    obj["Name"] = name;
    obj["Address"] = address;
    obj["Phone"] = phone;
    m_getData.pushData(obj);
}

void AddRequestController::setAnswer(const Request& request)
{
    m_model.addPerson(Person(request.getBody()["Id"].toInt(), request.getBody()["Name"].toString(), request.getBody()["Addres"].toString(), request.getBody()["Phone"].toString()));
}
