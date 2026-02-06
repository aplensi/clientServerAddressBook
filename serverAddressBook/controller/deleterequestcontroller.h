#ifndef DELETEREQUESTCONTROLLER_H
#define DELETEREQUESTCONTROLLER_H

#include "../usecases/deleterecordusecase.h"
#include "icontroller.h"

class DeleteRequestController : public IController
{
    DeleteRecordUseCase& m_usecase;
public:
    DeleteRequestController(DeleteRecordUseCase& usecase);
    QJsonObject handleRequest(const QJsonObject& body) override;
};

#endif // DELETEREQUESTCONTROLLER_H
