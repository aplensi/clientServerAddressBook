#include "query.h"

Query::Query(const QString& request) : m_request(request){}

Query::Query(const QString& request, const QList<Person>& persons) : m_request(request), m_persons(persons){}

QList<Person> Query::getPersons() const
{
    return m_persons;
}

QString Query::getRequest() const
{
    return m_request;
}
