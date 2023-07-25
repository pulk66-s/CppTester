#ifndef __CPP_MOCHA_INCLUDES_TESTS_BINARY_BINARY_HPP__
#define __CPP_MOCHA_INCLUDES_TESTS_BINARY_BINARY_HPP__

#include "./BinaryNamespace.hpp"
#include "Expect.hpp"
#include "Content.hpp"
#include <string>
#include <iostream>
#include <unordered_map>
#include <memory>

namespace Binary {
    class Bin {
    public:
        /**
         * @brief   Constructor of the class
         * @param path: path of the binary
        */
        Bin(std::string path);

        /**
         * @brief   Register a binary in the binaries map
         * @param name: name of the binary
         * @param bin: binary to register
        */
        static void registerBinary(std::string name, std::shared_ptr<Binary::Bin> bin);

        /**
         * @brief   Get the binary by the test name
         * @param name: name of the test
         * @return  the binary
        */
        static std::shared_ptr<Binary::Bin> getBinaryFromTest(std::string test);

        /**
         * @brief   Get the binary from the binaries map
         * @param name: name of the binary
         * @return  the binary
        */
        static std::shared_ptr<Binary::Bin> getBinary(std::string name);

        /**
         * @brief   Set the test binary map
        */
        static void setTestBinaryMap(std::string test, std::string binary);

        /**
         * @brief   Get the binary name from the test binary map
        */
        static std::string getBinaryNameFromTest(std::string test);

        /**
         * @brief   Get the expectation of the binary
         * @return  the expectation
        */
        struct Binary::Expect expect();

        /**
         * @brief   Get the binary content at the address
         * @param addr: address of the memory
         * @return  the value
        */
        uint8_t get(std::size_t addr);

    private:
        /**
         * @brief   Check if the binary in the path attribute exist
         * @throw   BinaryNotExisting if the binary doesn't exist
        */
        void checkIfBinaryExist();

        // Path of the binary
        std::string path;

        // Binary content
        uint8_t *content;

        // Binary size
        std::size_t size;
    };
}

#endif