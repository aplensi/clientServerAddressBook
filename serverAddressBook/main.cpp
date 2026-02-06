#include <QCoreApplication>
#include "server/server.h"
#include "controller/include.h"
#include "database/database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Database* database = Database::getInstance();

    AddRecordUseCase addReсord(*database);
    ChangeRecordUseCase changeRecord(*database);
    GetTableUseCase getTable(*database);
    DeleteRecordUseCase deleteRecord(*database);

    AddRequestController* addController = new AddRequestController(addReсord);
    ChangeRequestController* changeController = new ChangeRequestController(changeRecord);
    GetRequestController* getController = new GetRequestController(getTable);
    DeleteRequestController* deleteController = new DeleteRequestController(deleteRecord);
    ErrorRequestController* errorController = new ErrorRequestController;

    Server server;

    server.setControllers("Add", addController);
    server.setControllers("Change", changeController);
    server.setControllers("Get", getController);
    server.setControllers("Delete", deleteController);
    server.setControllers("Error", errorController);

    return a.exec();
}
