#ifndef DELETEREQUESTCONTROLLER_H
#define DELETEREQUESTCONTROLLER_H

#include "icontroller.h"
#include "../usecases/getdatausecase.h"
#include "../models/personmodel.h"
#include <QJsonObject>

class DeleteRequestController : public IController
{
    GetDataUseCase& m_getData;
    PersonModel& m_model;
public:
    DeleteRequestController(GetDataUseCase& getData, PersonModel& model);
    void sendRequest(int id);
    void setAnswer(const Request& request) override;
};

#endif // DELETEREQUESTCONTROLLER_H
