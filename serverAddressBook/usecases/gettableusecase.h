#ifndef GETTABLEUSECASE_H
#define GETTABLEUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class GetTableUseCase
{
    IPersonsRepository& m_repository;
public:
    GetTableUseCase(IPersonsRepository& repository);
    QList<Person> get();

};

#endif // GETTABLEUSECASE_H
