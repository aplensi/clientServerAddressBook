#ifndef DELETERECORDUSECASE_H
#define DELETERECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class DeleteRecordUseCase
{
    IPresonsRepository& m_repository;
public:
    DeleteRecordUseCase(IPresonsRepository& repository);

    void remove(const Request& request);
};

#endif // DELETERECORDUSECASE_H
