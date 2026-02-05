#include "changerecordusecase.h"

ChangeRecordUseCase::ChangeRecordUseCase(IPersonsSource &personSource) : m_personSource(personSource){}

void ChangeRecordUseCase::change(const Request &request)
{
    for(const Person& person : request.getPersons()){
        m_personSource.change(person.id(), person.name(), person.address(), person.phone());
    }
}

