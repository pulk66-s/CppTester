#ifndef __TESTS_TESTSUITE_HPP__
#define __TESTS_TESTSUITE_HPP__

#include "./TestNamespace.hpp"
#include <string>
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
         * @param name: test name
         * @param fn: function
        */
        void addTest(std::string group, std::string name, std::function<void()> fn);

        /**
         * @brief   Run all the test of all suites
        */
        static void run();

        /**
         * @brief   Getter for testsLists
        */
        std::unordered_map<std::string, std::function<void()>> list();

    private:
        // Test Suite list
        static std::unordered_map<std::string, TestSuite> testsSuites;

        // Test lists
        std::unordered_map<std::string, std::function<void()>> testList;
    };
}

#endif