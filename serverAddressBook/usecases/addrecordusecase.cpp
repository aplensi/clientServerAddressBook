#include "addrecordusecase.h"

AddRecordUseCase::AddRecordUseCase(IPersonsSource& personSource) : m_personSource(personSource){}

QList<Person> AddRecordUseCase::add(const Request &request)
{
    QList<Person> persons;
    for(const Person& person : request.getPersons()){
        persons.append(m_personSource.add(person.name(), person.address(), person.phone()));
    }
    return persons;
}

