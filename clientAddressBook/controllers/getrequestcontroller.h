#ifndef GETREQUESTCONTROLLER_H
#define GETREQUESTCONTROLLER_H

#include "icontroller.h"
#include "../usecases/getdatausecase.h"
#include "../models/personmodel.h"
#include <QJsonObject>
#include <QJsonArray>

class GetRequestController : public IController
{
    Q_OBJECT
    GetDataUseCase& m_getData;
    PersonModel& m_model;
public:
    GetRequestController(GetDataUseCase& getData, PersonModel& model);
    Q_INVOKABLE void sendRequest();
    void setAnswer(const Request& request) override;
};

#endif // GETREQUESTCONTROLLER_H
