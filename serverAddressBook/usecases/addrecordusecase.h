#ifndef ADDRECORDUSECASE_H
#define ADDRECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/query.h"

class AddRecordUseCase
{
    IPersonsSource& m_personSource;
public:
    AddRecordUseCase(IPersonsSource& personSource);
    void add(const Query& query);
};

#endif // ADDRECORDUSECASE_H
