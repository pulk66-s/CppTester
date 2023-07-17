/**
 * @package C++ 
 * @file Params.cpp
 * @brief Params Class
 * Params implementation of the project. It parse all the parameters of the program.
*/

#include "./Params.hpp"
#include <iostream>

Params::Params(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        this->_files.push_back(av[i]);
    }
}

std::vector<std::string> Params::files() const {
    return this->_files;
}