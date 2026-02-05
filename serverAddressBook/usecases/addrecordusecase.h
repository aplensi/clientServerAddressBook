#ifndef ADDRECORDUSECASE_H
#define ADDRECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h".h"

class AddRecordUseCase
{
    IPersonsSource& m_personSource;
public:
    AddRecordUseCase(IPersonsSource& personSource);
    void add(const Request& Request);
};

#endif // ADDRECORDUSECASE_H
