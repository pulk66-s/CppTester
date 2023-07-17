#ifndef __CORE_ERRORS_PARAMERROR_HPP__
#define __CORE_ERRORS_PARAMERROR_HPP__

#include "AError.hpp"

class ParamError : public AError
{
public:
    ParamError(const char *what, const char *where) : AError(what, where){};
};

#endif