#include "gettableusecase.h"

GetTableUseCase::GetTableUseCase(IPersonsRepository& repository) : m_repository(repository){}

QList<Person> GetTableUseCase::get()
{
    return m_repository.getData();
}

