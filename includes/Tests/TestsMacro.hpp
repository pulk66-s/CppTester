#ifndef __TESTS_TESTSMACRO_HPP__
#define __TESTS_TESTSMACRO_HPP__

#include "./TestSuite.hpp"
#include "./Binary/Binary.hpp"
#include <string>

#define Test(group, name)                                                     \
    void name##group(void);                                                   \
    static void __attribute__((constructor)) __##name##group(void)            \
    {                                                                         \
        Tests::TestSuite::registerTest(#name, #group, __FILE__, name##group); \
    }                                                                         \
    void name##group(void)

#define TestBinary(group, name, binaryPath)                                                      \
    void name##group(std::shared_ptr<Binary::Bin> bin);                                          \
    static void __attribute__((constructor)) __##name##group(void)                               \
    {                                                                                            \
        Tests::TestSuite::registerBinaryTest(#name, #group, __FILE__, #binaryPath, name##group); \
    }                                                                                            \
    void name##group(std::shared_ptr<Binary::Bin> bin)

#endif
