#include "maincontroller.h"

void MainController::setController(QString command, IController *controller)
{
    m_controllers[command] = controller;
}

void MainController::selectController(const Request &request)
{
    m_controllers[request.getCommand()]->setAnswer(request);
}
