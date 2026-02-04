#ifndef DELETERECORDUSECASE_H
#define DELETERECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/query.h"

class DeleteRecordUseCase
{
    IPersonsSource& m_personSource;
public:
    DeleteRecordUseCase(IPersonsSource& personSource);

    void remove(const Query& query);
};

#endif // DELETERECORDUSECASE_H
