#include "deleterecordusecase.h"

DeleteRecordUseCase::DeleteRecordUseCase(IPersonsRepository& repository) : m_repository(repository){}

void DeleteRecordUseCase::remove(const int id)
{
    m_repository.remove(id);
}

