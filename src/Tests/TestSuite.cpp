#include "Tests/TestSuite.hpp"
#include "Tests/Logger/Logger.hpp"
#include "Tests/Binary/Binary.hpp"
#include "Tests/Errors/AError.hpp"
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

    void TestSuite::registerBinaryTest(
        std::string name,
        std::string group,
        std::string suite,
        std::string binary,
        std::function<void(std::shared_ptr<Binary::Bin>)> fn
    ) {
        std::shared_ptr<Binary::Bin> bin = std::make_shared<Binary::Bin>(binary);

        if (!TestSuite::suiteExist(suite)) {
            TestSuite::createSuite(suite);
        }
        Binary::Bin::registerBinary(binary, bin);
        Binary::Bin::setTestBinaryMap(group + name, binary);
        TestSuite::testsSuites[suite].addBinaryTest(group, name, fn);
    }

    void TestSuite::addBinaryTest(std::string group, std::string name, std::function<void(std::shared_ptr<Binary::Bin>)> fn)
    {
        this->binaryTestList[group + name] = fn;
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

    int TestSuite::run()
    {
        Log::Logger logger;
        size_t totalFails = 0;

        for (std::pair<std::string, TestSuite> suite : TestSuite::testsSuites) {
            logger.title("Running:" + suite.first);
            size_t nbTests = 0, testsFailed = 0, testsSucceed = 0;
            for (auto test : suite.second.list()) {
                logger.subtitle(test.first);
                try {
                    test.second();
                    testsSucceed++;
                } catch (std::exception &e) {
                    logger.error(e.what());
                    testsFailed++;
                }
                nbTests++;
            }
            for (auto test : suite.second.binaryList()) {
                logger.subtitle(test.first);

                std::shared_ptr<Binary::Bin> bin = Binary::Bin::getBinaryFromTest(test.first);

                try {
                    test.second(bin);
                    testsSucceed++;
                } catch (std::exception &err) {
                    logger.error(err.what());
                    testsFailed++;
                }
                nbTests++;
            }
            if (testsFailed > 0) {
                logger.error(std::to_string(testsSucceed) + "/" + std::to_string(nbTests) + " tests succeed");
            } else {
                logger.success(std::to_string(testsSucceed) + "/" + std::to_string(nbTests) + " tests succeed");
            }
            totalFails += testsFailed;
        }
        return totalFails;
    }

    std::unordered_map<std::string, std::function<void()>> TestSuite::list()
    {
        return this->testList;
    }

    std::unordered_map<std::string, std::function<void(std::shared_ptr<Binary::Bin>)>> TestSuite::binaryList()
    {
        return this->binaryTestList;
    }
}