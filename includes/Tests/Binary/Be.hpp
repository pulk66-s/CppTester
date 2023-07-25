#ifndef __CPP_MOCHA_INCLUDES_TESTS_BINARY_BE_HPP__
#define __CPP_MOCHA_INCLUDES_TESTS_BINARY_BE_HPP__

#include "BinaryNamespace.hpp"
#include "Content.hpp"
#include "../Errors/OutOfRangeError.hpp"
#include "../Errors/AssertError.hpp"
#include <memory>
#include <iostream>

namespace Binary {
    /**
     * @brief   Be object
     * Object that test the value
    */
    struct Be
    {
    public:
        Be(std::shared_ptr<struct Binary::Content> value, std::size_t addr) : value(value), addr(addr) {};

        /**
         * @brief   Equal operator
         * @param expected: expected value
         * @return  true if the value is equal to the expected value
        */
        void equal(uint8_t expected) {
            if (this->addr >= this->value->size) {
                throw OutOfRangeError("Be::equal()", __FILE__);
            }
            if ((int)this->value->content[this->addr] == (int)expected) {
                return;
            }
            throw AssertError("Be::equal()", __FILE__);
        }

    private:
        std::shared_ptr<struct Binary::Content> value = nullptr;
        std::size_t addr = 0;
    };
}

#endif