/**
 * @package C++ 
 * @file Core.cpp
 * @brief Core class
 * Core implementation of the project
*/

#include "./Core.hpp"
#include "./Compilation/CompilFiles.hpp"
#include "./Compilation/CompilFlags.hpp"
#include "./Compilation/Compilation.hpp"

Core::Core(int ac, char **av) : params(ac, av)
{
    struct Compil::Files files(this->params);
    struct Compil::Flags flags;
    Compil::Compilation compilation(files, flags);
}

Core::~Core()
{
}