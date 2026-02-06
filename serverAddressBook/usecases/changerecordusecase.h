#ifndef CHANGERECORDUSECASE_H
#define CHANGERECORDUSECASE_H

#include "../database/database.h"

class ChangeRecordUseCase
{
    IPersonsRepository& m_repository;
public:
    ChangeRecordUseCase(IPersonsRepository& repository);
    void change(const Person& person);
};

#endif // CHANGERECORDUSECASE_H
