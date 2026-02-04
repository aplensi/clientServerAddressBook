#include <QCoreApplication>
#include "server/server.h"
#include "controller/controller.h"
#include "usecases/include.h"
#include "database/database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Database* database = Database::getInstance();

    AddRecordUseCase addReсord(*database);
    ChangeRecordUseCase changeRecord(*database);
    GetTableUseCase getTable(*database);
    DeleteRecordUseCase deleteRecord(*database);

    Server server;
    Controller controller(server, addReсord, changeRecord, getTable, deleteRecord);

    return a.exec();
}
