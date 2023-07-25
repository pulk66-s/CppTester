#ifndef __CPP_MOCHA_INCLUDES_TESTS_BINARY_MEMORY_HPP__
#define __CPP_MOCHA_INCLUDES_TESTS_BINARY_MEMORY_HPP__

#include "BinaryNamespace.hpp"
#include "To.hpp"
#include "Content.hpp"

namespace Binary {
    struct Memory {
    public:
        Memory(std::shared_ptr<struct Binary::Content> bin, std::size_t addr) : bin(bin), to(bin, addr) {};
        struct To to;

    private:
        std::shared_ptr<struct Binary::Content> bin = nullptr;
    };
}

#endif