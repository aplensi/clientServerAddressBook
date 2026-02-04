#ifndef CHANGERECORDUSECASE_H
#define CHANGERECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/query.h"

class ChangeRecordUseCase
{
    IPersonsSource& m_personSource;
public:
    ChangeRecordUseCase(IPersonsSource& personSource);
    void change(const Query& query);
};

#endif // CHANGERECORDUSECASE_H
