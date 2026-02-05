#include "addrecordusecase.h"

AddRecordUseCase::AddRecordUseCase(IPresonsRepository& repository) : m_repository(repository){}

QList<Person> AddRecordUseCase::add(const QList<Person>& persons)
{
    QList<Person> people;
    for(const Person& person : persons){
        people.append(m_repository.add(person.name(), person.address(), person.phone()));
    }
    return people;
}

