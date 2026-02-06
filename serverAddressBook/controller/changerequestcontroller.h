#ifndef CHANGEREQUESTCONTROLLER_H
#define CHANGEREQUESTCONTROLLER_H

#include "icontroller.h"
#include "../usecases/changerecordusecase.h"

class ChangeRequestController : public IController
{
    ChangeRecordUseCase& m_usecase;
public:
    ChangeRequestController(ChangeRecordUseCase& usecase);
    QJsonObject handleRequest(const QJsonObject& body) override;
};

#endif // CHANGEREQUESTCONTROLLER_H
