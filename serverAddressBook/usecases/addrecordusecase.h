#ifndef ADDRECORDUSECASE_H
#define ADDRECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h".h"

class AddRecordUseCase
{
    IPresonsRepository& m_repository;
public:
    AddRecordUseCase(IPresonsRepository& repository);
    QList<Person> add(const QList<Person>& persons);
};

#endif // ADDRECORDUSECASE_H
