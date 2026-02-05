#ifndef CHANGERECORDUSECASE_H
#define CHANGERECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class ChangeRecordUseCase
{
    IPresonsRepository& m_repository;
public:
    ChangeRecordUseCase(IPresonsRepository& repository);
    void change(const QList<Person>& persons);
};

#endif // CHANGERECORDUSECASE_H
