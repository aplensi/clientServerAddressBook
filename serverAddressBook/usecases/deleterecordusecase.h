#ifndef DELETERECORDUSECASE_H
#define DELETERECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class DeleteRecordUseCase
{
    IPersonsRepository& m_repository;
public:
    DeleteRecordUseCase(IPersonsRepository& repository);

    void remove(const int id);
};

#endif // DELETERECORDUSECASE_H
