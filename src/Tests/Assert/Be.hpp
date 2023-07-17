#ifndef __TESTS_ASSERT_BE_HPP__
#define __TESTS_ASSERT_BE_HPP__

#include "./AssertNamespace.hpp"

namespace Tests::Assert
{
    struct Be
    {
    public:
        Be(void *value);
        void equal(void *value);

    private:
        void *value = nullptr;
    };
}

#endif