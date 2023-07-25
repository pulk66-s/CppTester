#ifndef __CPP_MOCHA_INCLUDES_TESTS_BINARY_EXPECT_HPP__
#define __CPP_MOCHA_INCLUDES_TESTS_BINARY_EXPECT_HPP__

#include "BinaryNamespace.hpp"
#include "Memory.hpp"
#include "Content.hpp"

namespace Binary {
    struct Expect {
    public:
        Expect(std::shared_ptr<struct Binary::Content> bin) : bin(bin) {};

        /**
         * @brief   Memory selector
         * @param address: address of the memory
         * @return  Memory object
        */
        struct Binary::Memory memory(std::size_t address) {
            return Binary::Memory(this->bin, address);
        }

    private:
        std::shared_ptr<struct Binary::Content> bin = nullptr;
    };
}

#endif