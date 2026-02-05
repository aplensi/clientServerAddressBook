#include "addrecordusecase.h"

AddRecordUseCase::AddRecordUseCase(IPresonsRepository& repository) : m_repository(repository){}

QList<Person> AddRecordUseCase::add(const Request &request)
{
    QList<Person> persons;
    for(const Person& person : request.getPersons()){
        persons.append(m_repository.add(person.name(), person.address(), person.phone()));
    }
    return persons;
}

