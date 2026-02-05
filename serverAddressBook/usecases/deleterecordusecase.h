#ifndef DELETERECORDUSECASE_H
#define DELETERECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class DeleteRecordUseCase
{
    IPersonsSource& m_personSource;
public:
    DeleteRecordUseCase(IPersonsSource& personSource);

    void remove(const Request& request);
};

#endif // DELETERECORDUSECASE_H
