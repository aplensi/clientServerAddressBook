#ifndef GETTABLEUSECASE_H
#define GETTABLEUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class GetTableUseCase
{
    IPresonsRepository& m_repository;
public:
    GetTableUseCase(IPresonsRepository& repository);
    QList<Person> get();

};

#endif // GETTABLEUSECASE_H
