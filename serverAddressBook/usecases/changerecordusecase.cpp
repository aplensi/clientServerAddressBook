#include "changerecordusecase.h"

ChangeRecordUseCase::ChangeRecordUseCase(IPresonsRepository& repository) : m_repository(repository){}

void ChangeRecordUseCase::change(const Request &request)
{
    for(const Person& person : request.getPersons()){
        m_repository.change(person.id(), person.name(), person.address(), person.phone());
    }
}

