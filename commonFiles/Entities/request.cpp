#include "request.h"

Request::Request(const QString& request) : m_request(request){}

Request::Request(const QString& request, const QList<Person>& persons) : m_request(request), m_persons(persons){}

QList<Person> Request::getPersons() const
{
    return m_persons;
}

QString Request::getRequest() const
{
    return m_request;
}
