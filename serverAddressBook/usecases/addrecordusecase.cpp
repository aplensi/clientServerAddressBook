#include "addrecordusecase.h"

AddRecordUseCase::AddRecordUseCase(IPersonsSource& personSource) : m_personSource(personSource){}

void AddRecordUseCase::add(const Request &request)
{
    for(const Person& person : request.getPersons()){
        m_personSource.add(person.name(), person.address(), person.phone());
    }
}

