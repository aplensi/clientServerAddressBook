#ifndef ADDREQUESTCONTROLLER_H
#define ADDREQUESTCONTROLLER_H

#include "icontroller.h"
#include "../usecases/getdatausecase.h"
#include "../models/personmodel.h"
#include <QJsonObject>

class AddRequestController : public IController
{
    GetDataUseCase& m_getData;
    PersonModel& m_model;
public:
    AddRequestController(GetDataUseCase& getData, PersonModel& model);
    Q_INVOKABLE void sendRequest(const QString& name, const QString& address, const QString& phone);
    void setAnswer(const Request& request) override;
};

#endif // ADDREQUESTCONTROLLER_H
