#ifndef __CPP_MOCHA_INCLUDES_TESTS_BINARY_TO_HPP__
#define __CPP_MOCHA_INCLUDES_TESTS_BINARY_TO_HPP__

#include "BinaryNamespace.hpp"
#include <memory>
#include "Be.hpp"
#include "Content.hpp"

namespace Binary {
    /**
     * @brief   To object
     * Object that test the value
    */
    struct To
    {
    public:
        To(std::shared_ptr<struct Binary::Content> value, std::size_t addr) : value(value), be(value, addr) {};
        struct Be be;

    private:
        std::shared_ptr<struct Binary::Content> value = nullptr;
    };
}

#endif