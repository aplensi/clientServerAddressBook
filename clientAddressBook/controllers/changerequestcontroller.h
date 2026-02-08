#ifndef CHANGEREQUESTCONTROLLER_H
#define CHANGEREQUESTCONTROLLER_H

#include "icontroller.h"
#include "../usecases/getdatausecase.h"
#include "../../commonFiles/Entities/person.h"
#include "../models/personmodel.h"
#include <QJsonObject>

class ChangeRequestController : public IController
{
    GetDataUseCase& m_getData;
    PersonModel& m_model;
public:
    ChangeRequestController(GetDataUseCase& getData, PersonModel& model);
    void sendRequest(const Person& person);
    void setAnswer(const Request& request) override;
};

#endif // CHANGEREQUESTCONTROLLER_H
