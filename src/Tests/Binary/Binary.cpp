#include "Tests/Binary/Binary.hpp"
#include "Tests/Errors/BinaryNotExisting.hpp"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <filesystem>

namespace Binary {
    /**
     * @brief   Map of binaries
     * It stores the binaries that are tested
    */
    static std::unordered_map<std::string, std::shared_ptr<Binary::Bin>> binaries;

    /**
     * @brief   Map of binaries path
     * It stores the binaries path that are tested
    */
    std::unordered_map<std::string, std::string> testBinaryMap;

    Bin::Bin(std::string path) {
        this->path = path;
        this->checkIfBinaryExist();
    }

    void Bin::checkIfBinaryExist() {
        std::ifstream file(this->path.c_str(), std::ios_base::binary);

        if (!file.good()) {
            throw BinaryNotExisting(this->path.c_str(), __FILE__);
        }
        this->size = std::filesystem::file_size(this->path);
        this->content = new uint8_t[this->size + 1];
        for (std::size_t i = 0; i < this->size + 1; this->content[i++] = '\0');
        file.readsome((char *)this->content, this->size);
        file.close();
    }

    void Bin::registerBinary(std::string name, std::shared_ptr<Binary::Bin> bin) {
        binaries[name] = bin;
    }

    void Bin::setTestBinaryMap(std::string test, std::string binary) {
        testBinaryMap[test] = binary;
    }

    std::shared_ptr<Binary::Bin> Bin::getBinary(std::string name) {
        if (binaries.find(name) == binaries.end()) {
            std::cerr << "getBinary() " << name << std::endl;
            throw BinaryNotExisting(name.c_str(), __FILE__);
        }
        return binaries[name];
    }

    std::string Bin::getBinaryNameFromTest(std::string test) {
        if (testBinaryMap.find(test) == testBinaryMap.end()) {
            std::cerr << "getBinaryNameFromTest() " << test << std::endl;
            throw BinaryNotExisting(test.c_str(), __FILE__);
        }
        return testBinaryMap[test];
    }

    std::shared_ptr<Binary::Bin> Bin::getBinaryFromTest(std::string test) {
        std::string binaryName = Bin::getBinaryNameFromTest(test);
        return Bin::getBinary(binaryName);
    }

    struct Binary::Expect Bin::expect() {
        std::shared_ptr<struct Binary::Content> content = std::make_shared<struct Binary::Content>();

        content->path = this->path;
        content->content = this->content;
        content->size = this->size;

        struct Binary::Expect res(content);

        return res;
    }

    uint8_t Bin::get(std::size_t addr) {
        return this->content[addr];
    }
}