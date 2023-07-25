#ifndef __CPP_MOCHA_INCLUDES_TESTS_BINARY_CONTENT_HPP__
#define __CPP_MOCHA_INCLUDES_TESTS_BINARY_CONTENT_HPP__

#include "BinaryNamespace.hpp"
#include <string>

namespace Binary {
    struct Content {
        std::string path;
        uint8_t *content;
        std::size_t size;
    };
}

#endif