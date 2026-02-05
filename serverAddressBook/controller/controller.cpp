#include "controller.h"

void Controller::definitionQuery(Client client)
{
    Request request = jsonParser.toRequest(client.getDataArray());
    if(request.getRequest() == "get"){
        m_server.send(jsonParser.toByteArray(Request(request.getRequest(), m_getTable.get())), client);
    }else if(request.getRequest() == "delete"){
        m_deleteRecord.remove(request);
        m_server.send(jsonParser.toByteArray(Request("success")), client);
    }else if(request.getRequest() == "add"){
        m_server.send(jsonParser.toByteArray(Request("add", m_addRecord.add(request))), client);
    }else if(request.getRequest() == "change"){
        m_changeRecord.change(request);
        m_server.send(jsonParser.toByteArray(Request("success")), client);
    }else{
        qDebug() << "Invalid request. Client: " << client.getAddress() << ":" << client.getPort();
        m_server.send(jsonParser.toByteArray(Request("error")), client);
        return;
    }
}

Controller::Controller(Server& server, AddRecordUseCase& addRecord, ChangeRecordUseCase& changeRecord, GetTableUseCase& getTable, DeleteRecordUseCase& deleteRecord)
    : m_server(server), m_addRecord(addRecord), m_changeRecord(changeRecord), m_getTable(getTable), m_deleteRecord(deleteRecord)
{
    m_server.receive();
    connect(&m_server, &Server::receivedData, this, &Controller::definitionQuery);
}
