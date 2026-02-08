#include "addrequestcontroller.h"

AddRequestController::AddRequestController(GetDataUseCase &getData, PersonModel& model)
    : m_getData(getData), m_model(model){}

void AddRequestController::sendRequest(const Person &person)
{
    QJsonObject obj;
    obj["Command"] = "Add";
    obj["Name"] = person.name();
    obj["Address"] = person.address();
    obj["Phone"] = person.phone();
    m_getData.pushData(obj);
}

void AddRequestController::setAnswer(const Request& request)
{
    m_model.addPerson(Person(request.getBody()["Id"].toInt(), request.getBody()["Name"].toString(), request.getBody()["Addres"].toString(), request.getBody()["Phone"].toString()));
}
