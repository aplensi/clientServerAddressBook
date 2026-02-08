#ifndef GETDATAUSECASE_H
#define GETDATAUSECASE_H

#include "../client/iclient.h"

class GetDataUseCase
{
    IClient& m_client;
public:
    GetDataUseCase(IClient& client);
    void pushData(const QJsonObject& body);
};

#endif // GETDATAUSECASE_H
