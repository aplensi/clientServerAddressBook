#include <models/personmodel.h>
#include <models/proxymodel.h>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controllers/addrequestcontroller.h"
#include "controllers/changerequestcontroller.h"
#include "controllers/deleterequestcontroller.h"
#include "controllers/getrequestcontroller.h"
#include "usecases/getdatausecase.h"
#include "client/client.h"
#include "controllers/maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;

    PersonModel model;
    ProxyModel proxyModel(&engine);

    proxyModel.setSourceModel(&model);

    QHostAddress address = QHostAddress::LocalHost;
    Client client(address, 25565);

    MainController mainController;
    GetDataUseCase getData(client);

    AddRequestController* addController = new AddRequestController(getData, model);
    ChangeRequestController* changeController = new ChangeRequestController(getData, model);
    DeleteRequestController* deleteController = new DeleteRequestController(getData, model);
    GetRequestController* getController = new GetRequestController(getData, model);

    mainController.setController("Add", addController);
    mainController.setController("Change", changeController);
    mainController.setController("Delete", deleteController);
    mainController.setController("Get", getController);

    QObject::connect(&client, &Client::dataReceived, &mainController, &MainController::selectController);

    engine.rootContext()->setContextProperty("Person", &proxyModel);
    engine.rootContext()->setContextProperty("AddController", addController);
    engine.rootContext()->setContextProperty("DeleteController", deleteController);
    engine.rootContext()->setContextProperty("ChangeController", changeController);

    engine.load(QUrl("qrc:/view/main.qml"));

    getController->sendRequest();

    if (engine.rootObjects().isEmpty())
        return -1;

    return a.exec();
}
