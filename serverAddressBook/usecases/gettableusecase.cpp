#include "gettableusecase.h"

GetTableUseCase::GetTableUseCase(IPersonsSink &personSink) : m_personSink(personSink){}

QList<Person> GetTableUseCase::get()
{
    return m_personSink.getData();
}

