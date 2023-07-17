#ifndef __TESTS_ASSERT_TO_HPP__
#define __TESTS_ASSERT_TO_HPP__

#include "./AssertNamespace.hpp"
#include "./Be.hpp"

namespace Tests::Assert
{
    struct To
    {
    public:
        To(void *value);
        struct Be be;

    private:
        void *value = nullptr;
    };
}

#endif