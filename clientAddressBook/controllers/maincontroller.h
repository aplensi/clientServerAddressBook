#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QHash>
#include "icontroller.h"

class MainController : public QObject
{
    Q_OBJECT
    QHash<QString, IController*> m_controllers;
public:
    void setController(QString command, IController* controller);
public slots:
    void selectController(const Request& request);
};

#endif // MAINCONTROLLER_H
