#ifndef QUERY_H
#define QUERY_H

#include "person.h"
#include <QtCore>

class Query
{
    QString m_request;
    QList<Person> m_persons;
public:
    Query(const QString& request);
    Query(const QString& request, const QList<Person>& persons);
    QList<Person> getPersons() const;
    QString getRequest() const;
};

#endif // QUERY_H
