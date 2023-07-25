#ifndef __TESTS_TESTSUITE_HPP__
#define __TESTS_TESTSUITE_HPP__

#include "./TestNamespace.hpp"
#include "./Binary/Binary.hpp"
#include <string>
#include <memory>
#include <functional>
#include <unordered_map>

namespace Tests
{

    class TestSuite
    {
    public:
        ~TestSuite();

        /**
         * @brief   Register a test in a test suite
         * @param name: name of the test
         * @param grop: group of the test
         * @param suite: suite name of the test
         * @param fn: test
        */
        static void registerTest(
            std::string name,
            std::string group,
            std::string suite,
            std::function<void()> fn
        );

        /**
         * @brief   Register a binary test in a test suite
         * @param name: name of the test
         * @param grop: group of the test
         * @param suite: suite name of the test
         * @param binary: the binary to test
         * @param fn: test
        */
        static void registerBinaryTest(
            std::string name,
            std::string group,
            std::string suite,
            std::string binary,
            std::function<void(std::shared_ptr<Binary::Bin>)> fn
        );

        /**
         * @brief   Check if a test suite exists with a name
         * @param suite: suit name
         * @return: true if exists, false if not
        */
        static bool suiteExist(std::string name);

        /**
         * @brief   Create a test suite
         * @param suite: suit name
        */
        static void createSuite(std::string suite);

        /**
         * @brief   Add a test to the current suite test
         * @param group: test group
         * @param name: test name
         * @param fn: function
        */
        void addTest(std::string group, std::string name, std::function<void()> fn);

        /**
         * @brief   Add a binary test to the current suite test
         * @param group: test group
         * @param name: test name
         * @param fn: function
        */
        void addBinaryTest(std::string group, std::string name, std::function<void(std::shared_ptr<Binary::Bin>)> fn);

        /**
         * @brief   Run all the test of all suites
        */
        static void run();

        /**
         * @brief   Getter for testsLists
        */
        std::unordered_map<std::string, std::function<void()>> list();

        /**
         * @brief   Getter for binaryTestList
        */
        std::unordered_map<std::string, std::function<void(std::shared_ptr<Binary::Bin>)>> binaryList();

    private:
        // Test Suite list
        static std::unordered_map<std::string, TestSuite> testsSuites;

        // Test lists
        std::unordered_map<std::string, std::function<void()>> testList;

        // Binary test lists
        std::unordered_map<std::string, std::function<void(std::shared_ptr<Binary::Bin>)>> binaryTestList;
    };
}

#endif