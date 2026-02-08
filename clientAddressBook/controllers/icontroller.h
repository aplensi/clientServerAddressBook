#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "../entities/request.h"

class IController
{
public:
    virtual ~IController() = default;
    virtual void setAnswer(const Request& request) = 0;
};

#endif // ICONTROLLER_H
