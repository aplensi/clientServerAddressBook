#ifndef CHANGEREQUESTCONTROLLER_H
#define CHANGEREQUESTCONTROLLER_H

#include "icontroller.h"
#include "../usecases/getdatausecase.h"
#include "../../commonFiles/Entities/person.h"
#include "../models/personmodel.h"
#include <QJsonObject>

class ChangeRequestController : public IController
{
    Q_OBJECT
    GetDataUseCase& m_getData;
    PersonModel& m_model;
public:
    ChangeRequestController(GetDataUseCase& getData, PersonModel& model);
    Q_INVOKABLE void sendRequest(const int id, const QString& name, const QString& address, const QString& phone);
    void setAnswer(const Request& request) override;
};

#endif // CHANGEREQUESTCONTROLLER_H
