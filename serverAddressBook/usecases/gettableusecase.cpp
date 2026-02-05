#include "gettableusecase.h"

GetTableUseCase::GetTableUseCase(IPresonsRepository& repository) : m_repository(repository){}

QList<Person> GetTableUseCase::get()
{
    return m_repository.getData();
}

