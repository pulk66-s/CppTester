/**
 * @package C++ 
 * @file Core.cpp
 * @brief Core class
 * Core implementation of the project
*/

#include "./Core.hpp"
#include "./Compilation/CompilFiles.hpp"
#include "./Compilation/CompilFlags.hpp"
#include "./Compilation/BuiltinFiles.hpp"
#include "./Compilation/Compilation.hpp"
#include "./Errors/EnvError.hpp"
#include <iostream>

Core::Core(int ac, char **av) : datas(ac, av)
{
    struct Compil::Files files(this->datas.params);
    struct Compil::BuiltinFiles builtinFiles(this->datas);
    struct Compil::Flags flags;
    Compil::Compilation compilation(files, builtinFiles, flags, this->datas);

    compilation.run();
    int res = compilation.runprgm();

    if (res != 0) {
        std::cout << "Compilation failed " << res << " tests failed" << std::endl;;
    }
    this->nbFailure = res;
}

Core::~Core()
{
}
