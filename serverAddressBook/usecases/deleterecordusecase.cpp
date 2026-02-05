#include "deleterecordusecase.h"

DeleteRecordUseCase::DeleteRecordUseCase(IPresonsRepository& repository) : m_repository(repository){}

void DeleteRecordUseCase::remove(const QList<Person>& persons)
{
    for(const Person& person : persons){
        m_repository.remove(person.id());
    }
}

