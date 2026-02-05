#ifndef CHANGERECORDUSECASE_H
#define CHANGERECORDUSECASE_H

#include "../database/database.h"
#include "../../commonFiles/Entities/request.h"

class ChangeRecordUseCase
{
    IPersonsSource& m_personSource;
public:
    ChangeRecordUseCase(IPersonsSource& personSource);
    void change(const Request& request);
};

#endif // CHANGERECORDUSECASE_H
