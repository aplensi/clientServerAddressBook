#include "getdatausecase.h"

GetDataUseCase::GetDataUseCase(IClient &client) : m_client(client){}

void GetDataUseCase::pushData(const QJsonObject& body)
{
    m_client.send(body);
}
