#ifndef __TESTS_ASSERT_TO_HPP__
#define __TESTS_ASSERT_TO_HPP__

#include "./AssertNamespace.hpp"
#include "./Be.hpp"

namespace Tests::Assert
{
    template <typename T>
    struct To
    {
    public:
        /**
         * @brief   Constructor
         * @param value: Value to test
        */
        To(T value) : be(value), value(value){};

        /**
         * @brief   value tester, it contains every function to check the value
        */
        struct Be<T> be;

    private:
        T value = nullptr;
    };
}

#endif