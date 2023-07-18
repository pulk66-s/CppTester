#ifndef __TESTS_ASSERT_ASSERT_HPP__
#define __TESTS_ASSERT_ASSERT_HPP__

#include "./AssertNamespace.hpp"
#include "./To.hpp"

/**
 * @brief   Entry of the expect function
 * @param value: The value that need to be tested
 * @return: Expect object
 */
template <typename T>
struct Tests::Assert::Expect<T> expect(T value)
{
    struct Tests::Assert::Expect<T> res(value);

    return res;
}

namespace Tests::Assert
{
    /**
     * @brief   Expect object
     * Object that test the value
     */
    template <typename T>
    struct Expect
    {
    public:
        Expect(T value) : to(value), value(value){};
        struct To<T> to;

    private:
        T value = nullptr;
    };
}

#endif