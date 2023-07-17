#ifndef __TESTS_ASSERT_ASSERT_HPP__
#define __TESTS_ASSERT_ASSERT_HPP__

#include "./AssertNamespace.hpp"
#include "./To.hpp"


namespace Tests::Assert {
    /**
     * @brief   Entry of the expect function
     * @param value: The value that need to be tested
     * @return: Expect object
    */
    struct Expect expect(void *value);

    /**
     * @brief   Expect object
     * Object that test the value
    */
    struct Expect {
    public:
        Expect(void *value);
        struct To to;

    private:
        void *value = nullptr;
    };
}

#endif