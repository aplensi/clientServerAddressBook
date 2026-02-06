#ifndef ADDREQUESTCONTROLLER_H
#define ADDREQUESTCONTROLLER_H

#include "icontroller.h"
#include "../usecases/addrecordusecase.h"
#include <QJsonObject>
#include <QJsonArray>

class AddRequestController : public IController
{
    AddRecordUseCase& m_usecase;
public:
    AddRequestController(AddRecordUseCase& usecase);
    QJsonObject handleRequest(const QJsonObject& body) override;
};

#endif // ADDREQUESTCONTROLLER_H
