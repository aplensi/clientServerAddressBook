#include "addrequestcontroller.h"

AddRequestController::AddRequestController(AddRecordUseCase& usecase) : m_usecase(usecase){}

QJsonObject AddRequestController::handleRequest(const QJsonObject &body)
{
    Person pers(m_usecase.add(body["Name"].toString(), body["Addres"].toString(), body["Phone"].toString()));
    QJsonObject obj;
    obj["Command"] = "Add";
    obj["Id"] = pers.id();
    obj["Name"] = pers.name();
    obj["Address"] = pers.address();
    obj["Phone"] = pers.phone();
    return obj;
}
