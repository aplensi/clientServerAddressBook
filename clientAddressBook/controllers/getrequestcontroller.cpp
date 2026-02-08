#include "getrequestcontroller.h"

GetRequestController::GetRequestController(GetDataUseCase &getData, PersonModel &model)
    : m_getData(getData), m_model(model){}

void GetRequestController::sendRequest()
{
    QJsonObject obj;
    obj["Command"] = "Get";
    m_getData.pushData(obj);
}

void GetRequestController::setAnswer(const Request &request)
{
    QList<Person> persons;
    QJsonObject obj = request.getBody();
    QJsonArray arrayJ = obj["Persons"].toArray();
    for(const auto &value : arrayJ){
        QJsonObject person = value.toObject();
        persons.append(Person(person["Id"].toInt(), person["Name"].toString(), person["Address"].toString(), person["Phone"].toString()));
    }
    m_model.setPeople(persons);
}
