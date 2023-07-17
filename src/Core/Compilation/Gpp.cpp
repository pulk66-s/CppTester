/**
 * @package C++
 * @file Gpp.cpp
 * @brief Gpp class
 * Gpp class implementation of the project.
 * This class manages all the compilation process of the files
 */

#include "./Gpp.hpp"
#include <iostream>

namespace Compil
{

    std::string Gpp::_formatCommand(std::vector<std::string> files, std::vector<std::string> flags)
    {
        std::string joinedFiles = "";
        std::string joinedFlags = "";

        for (std::string file : files) {
            joinedFiles += file + " ";
        }
        for (std::string flag : flags) {
            joinedFlags += flag + " ";
        }
        return this->compiler + " " + joinedFiles + joinedFlags;
    }

    void Gpp::run(std::vector<std::string> files, std::vector<std::string> flags)
    {
        std::string command = this->_formatCommand(files, flags);

        system(command.c_str());
    }
}