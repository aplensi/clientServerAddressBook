#ifndef QUERY_H
#define QUERY_H

#include "person.h"
#include <QtCore>

class Request
{
    QString m_request;
    QList<Person> m_persons;
public:
    Request(const QString& request);
    Request(const QString& request, const QList<Person>& persons);
    QList<Person> getPersons() const;
    QString getRequest() const;
};

#endif // QUERY_H
