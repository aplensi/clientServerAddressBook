#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../usecases/include.h"
#include "../server/server.h"
#include "../../commonFiles/DataTransformer/jsoncontroller.h"
#include "../entity/client.h"

class Controller : public QObject
{
Q_OBJECT
    JsonController jsonController;
    Server& m_server;

    AddRecordUseCase m_addRecord;
    ChangeRecordUseCase m_changeRecord;
    GetTableUseCase m_getTable;
    DeleteRecordUseCase m_deleteRecord;

    void definitionQuery(Client client);
public:
    Controller(Server& server, AddRecordUseCase& addRecord, ChangeRecordUseCase& changeRecord, GetTableUseCase& getTable, DeleteRecordUseCase& deleteRecord);
};

#endif // CONTROLLER_H
