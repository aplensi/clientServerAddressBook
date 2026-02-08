#ifndef ICLIENT_H
#define ICLIENT_H

#include "../entities/request.h"
#include <QJsonObject>

class IClient: public QObject{
    Q_OBJECT
public:
    virtual ~IClient() = default;
    virtual void send(const QJsonObject& response) = 0;
signals:
    void dataReceived(const Request& request);
};

#endif // ICLIENT_H
