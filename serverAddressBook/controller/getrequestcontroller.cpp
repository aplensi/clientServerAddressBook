#include "getrequestcontroller.h"

GetRequestController::GetRequestController(GetTableUseCase &usecase) : m_usecase(usecase){}

QJsonObject GetRequestController::handleRequest(const QJsonObject &body)
{
    QList<Person> persons;
    persons = m_usecase.get();
    QJsonObject objJ;
    QJsonArray arrayJ;

    for(const Person& pers : persons){
        QJsonObject personJ;
        personJ["Id"] = pers.id();
        personJ["Name"] = pers.name();
        personJ["Address"] = pers.address();
        personJ["Phone"] = pers.phone();
        arrayJ.append(personJ);
    }

    objJ["Command"] = "Get";
    objJ["Persons"] = arrayJ;
    return objJ;
}

