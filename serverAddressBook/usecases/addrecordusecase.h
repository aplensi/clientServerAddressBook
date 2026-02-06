#ifndef ADDRECORDUSECASE_H
#define ADDRECORDUSECASE_H

#include "../database/database.h"

class AddRecordUseCase
{
    IPersonsRepository& m_repository;
public:
    AddRecordUseCase(IPersonsRepository& repository);
    Person add(const QString& name, const QString& address, const QString& phone);
};

#endif // ADDRECORDUSECASE_H
