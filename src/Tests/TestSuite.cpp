#include "Tests/TestSuite.hpp"
#include "Tests/Logger/Logger.hpp"
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
        Log::Logger logger;

        for (std::pair<std::string, TestSuite> suite : TestSuite::testsSuites) {
            logger.title("Running:" + suite.first);
            for (auto test : suite.second.list()) {
                logger.subtitle(test.first);
                test.second();
            }
        }
    }

    std::unordered_map<std::string, std::function<void()>> TestSuite::list()
    {
        return this->testList;
    }
}