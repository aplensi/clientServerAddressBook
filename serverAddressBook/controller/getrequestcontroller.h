#ifndef GETREQUESTCONTROLLER_H
#define GETREQUESTCONTROLLER_H

#include "../usecases/gettableusecase.h"
#include "icontroller.h"
#include <QJsonObject>
#include <QJsonArray>

class GetRequestController : public IController
{
    GetTableUseCase& m_usecase;
public:
    GetRequestController(GetTableUseCase& usecase);
    QJsonObject handleRequest(const QJsonObject& body) override;
};

#endif // GETREQUESTCONTROLLER_H
