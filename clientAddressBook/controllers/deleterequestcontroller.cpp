#include "deleterequestcontroller.h"

DeleteRequestController::DeleteRequestController(GetDataUseCase &getData, PersonModel &model)
    : m_getData(getData), m_model(model){}

void DeleteRequestController::sendRequest(int id)
{
    QJsonObject obj;
    obj["Command"] = "Delete";
    obj["Id"] = id;
    m_getData.pushData(obj);
}

void DeleteRequestController::setAnswer(const Request &request)
{
    m_model.remove(request.getBody()["Id"].toInt());
}
