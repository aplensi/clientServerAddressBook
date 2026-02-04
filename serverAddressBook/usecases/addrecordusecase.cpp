#include "addrecordusecase.h"

AddRecordUseCase::AddRecordUseCase(IPersonsSource& personSource) : m_personSource(personSource){}

void AddRecordUseCase::add(const Query &query)
{
    for(const Person& person : query.getPersons()){
        m_personSource.add(person.name(), person.address(), person.phone());
    }
}

