#include "deleterecordusecase.h"

DeleteRecordUseCase::DeleteRecordUseCase(IPersonsSource &personSource) : m_personSource(personSource){}

void DeleteRecordUseCase::remove(const Query &query)
{
    for(const Person& person : query.getPersons()){
        m_personSource.remove(person.id());
    }
}

