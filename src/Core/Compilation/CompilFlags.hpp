#ifndef __COMPILATION_COMPILFLAGS_HPP__
#define __COMPILATION_COMPILFLAGS_HPP__

#include "./CompilationNamespace.hpp"

namespace Compil
{
    struct Flags
    {
        bool debug = false;         // Debugging flags (-g3 and -fsanitize)
        bool optimisation = false;  // Optimisation flags
        bool warns = true;          // Warning flags
        bool warnError = false;     // Warn Error flag (-Werror)
        bool defaultInclude = true; // Default include folder path
        bool defaultName = true;    // Default binary name
    };
}

#endif