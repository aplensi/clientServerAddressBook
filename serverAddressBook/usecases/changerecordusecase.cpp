#include "changerecordusecase.h"

ChangeRecordUseCase::ChangeRecordUseCase(IPersonsRepository& repository) : m_repository(repository){}

void ChangeRecordUseCase::change(const Person& person)
{
    m_repository.change(person.id(), person.name(), person.address(), person.phone());
}

