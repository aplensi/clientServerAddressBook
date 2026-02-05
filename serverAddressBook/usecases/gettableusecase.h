#ifndef GETTABLEUSECASE_H
#define GETTABLEUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class GetTableUseCase
{
    IPersonsSink& m_personSink;
public:
    GetTableUseCase(IPersonsSink& personSink);
    QList<Person> get();

};

#endif // GETTABLEUSECASE_H
