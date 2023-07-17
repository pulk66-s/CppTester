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

Core::Core(int ac, char **av) : params(ac, av)
{
    struct Compil::Files files(this->params);
    struct Compil::BuiltinFiles builtinFiles(this->env, this->params);
    struct Compil::Flags flags;
    Compil::Compilation compilation(files, builtinFiles, flags);

    compilation.run();
}

Core::~Core()
{
}