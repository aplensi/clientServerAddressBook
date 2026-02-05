#include "deleterecordusecase.h"

DeleteRecordUseCase::DeleteRecordUseCase(IPersonsSource &personSource) : m_personSource(personSource){}

void DeleteRecordUseCase::remove(const Request &request)
{
    for(const Person& person : request.getPersons()){
        m_personSource.remove(person.id());
    }
}

