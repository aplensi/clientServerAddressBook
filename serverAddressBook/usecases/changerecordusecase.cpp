#include "changerecordusecase.h"

ChangeRecordUseCase::ChangeRecordUseCase(IPersonsSource &personSource) : m_personSource(personSource){}

void ChangeRecordUseCase::change(const Query &query)
{
    for(const Person& person : query.getPersons()){
        m_personSource.change(person.id(), person.name(), person.address(), person.phone());
    }
}

