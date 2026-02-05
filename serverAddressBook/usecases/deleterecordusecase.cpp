#include "deleterecordusecase.h"

DeleteRecordUseCase::DeleteRecordUseCase(IPresonsRepository& repository) : m_repository(repository){}

void DeleteRecordUseCase::remove(const Request &request)
{
    for(const Person& person : request.getPersons()){
        m_repository.remove(person.id());
    }
}

