#ifndef __TESTS_ERRORS_ASSERTERROR_HPP__
#define __TESTS_ERRORS_ASSERTERROR_HPP__

#include "AError.hpp"

class AssertError : public AError
{
public:
    AssertError(const char *what, const char *where) : AError(what, where){};
};

#endif