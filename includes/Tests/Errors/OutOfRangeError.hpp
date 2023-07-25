#ifndef __CPP_MOCHA_INCLUDES_TESTS_ERRORS_OUTOFRANGEERROR_HPP__
#define __CPP_MOCHA_INCLUDES_TESTS_ERRORS_OUTOFRANGEERROR_HPP__

#include "AError.hpp"

class OutOfRangeError : public AError {
public:
    OutOfRangeError(std::string const &message, std::string const &file) : AError(message, file) {};
};

#endif