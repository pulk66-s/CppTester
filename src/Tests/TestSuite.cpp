#include "Tests/TestSuite.hpp"
#include <iostream>

namespace Tests
{
    std::unordered_map<std::string, TestSuite> TestSuite::testsSuites = {};

    TestSuite::~TestSuite() {}

    void TestSuite::registerTest(
        std::string name,
        std::string group,
        std::string suite,
        std::function<void()> fn
    ) {
        if (!TestSuite::suiteExist(suite)) {
            TestSuite::createSuite(suite);
        }
        TestSuite::testsSuites[suite].addTest(group, name, fn);
    }

    bool TestSuite::suiteExist(std::string name)
    {
        return TestSuite::testsSuites.find(name) != TestSuite::testsSuites.end();
    }

    void TestSuite::createSuite(std::string suite)
    {
        TestSuite::testsSuites[suite] = TestSuite();
    }

    void TestSuite::addTest(std::string group, std::string name, std::function<void()> fn)
    {
        this->testList[group + name] = fn;
    }

    void TestSuite::run()
    {
        for (std::pair<std::string, TestSuite> suite : TestSuite::testsSuites) {
            for (auto test : suite.second.list()) {
                test.second();
            }
        }
    }

    std::unordered_map<std::string, std::function<void()>> TestSuite::list()
    {
        return this->testList;
    }
}