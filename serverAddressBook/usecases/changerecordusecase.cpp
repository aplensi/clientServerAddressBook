#include "changerecordusecase.h"

ChangeRecordUseCase::ChangeRecordUseCase(IPresonsRepository& repository) : m_repository(repository){}

void ChangeRecordUseCase::change(const QList<Person>& persons)
{
    for(const Person& person : persons){
        m_repository.change(person.id(), person.name(), person.address(), person.phone());
    }
}

