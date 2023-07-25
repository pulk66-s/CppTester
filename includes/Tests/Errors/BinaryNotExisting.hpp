#ifndef __TESTS_ERRORS_BINARYNOTEXISTING_HPP__
#define __TESTS_ERRORS_BINARYNOTEXISTING_HPP__

#include "AError.hpp"

class BinaryNotExisting : public AError
{
public:
    BinaryNotExisting(const char *what, const char *where) : AError(what, where){};
};

#endif