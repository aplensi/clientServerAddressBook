#include "addrecordusecase.h"

AddRecordUseCase::AddRecordUseCase(IPersonsRepository& repository) : m_repository(repository){}

Person AddRecordUseCase::add(const QString& name, const QString& address, const QString& phone)
{
    return m_repository.add(name, address, phone);
}

