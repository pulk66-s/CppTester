/**
 * @package C++ 
 * @file CompilFiles.cpp
 * @brief CompilFiles class
 * CompilFiles class implementation of the project.
 * It's describing all the files to compil
*/

#include "./CompilFiles.hpp"

namespace Compil {
    Files::Files(Params params) {
        this->files = params.files();
    }

    Files::Files() {
        this->files = {};
    }
}