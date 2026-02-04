#include "controller.h"

void Controller::definitionQuery(Client client)
{
    Query query = jsonController.toQuery(client.getDataArray());
    if(query.getRequest() == "get"){
        m_server.send(jsonController.toByteArray(Query(query.getRequest(), m_getTable.get())), client);
    }else if(query.getRequest() == "delete"){
        m_deleteRecord.remove(query);
    }else if(query.getRequest() == "add"){
        m_addRecord.add(query);
    }else if(query.getRequest() == "change"){
        m_changeRecord.change(query);
    }else{
        qDebug() << "Invalid request. Client: " << client.getAddress() << ":" << client.getPort();
        return;
    }
}

Controller::Controller(Server& server, AddRecordUseCase& addRecord, ChangeRecordUseCase& changeRecord, GetTableUseCase& getTable, DeleteRecordUseCase& deleteRecord)
    : m_server(server), m_addRecord(addRecord), m_changeRecord(changeRecord), m_getTable(getTable), m_deleteRecord(deleteRecord)
{
    m_server.receive();
    connect(&m_server, &Server::receivedData, this, &Controller::definitionQuery);
}
