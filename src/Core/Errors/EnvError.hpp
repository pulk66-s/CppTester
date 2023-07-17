#ifndef __CORE_ERRORS_ENVERROR_HPP__
#define __CORE_ERRORS_ENVERROR_HPP__

#include "AError.hpp"

class EnvError : public AError
{
public:
    EnvError(const char *what, const char *where) : AError(what, where){};
};

#endif