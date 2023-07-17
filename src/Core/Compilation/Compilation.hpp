#ifndef __COMPILATION_COMPILATION_HPP__
#define __COMPILATION_COMPILATION_HPP__

#include "CompilationNamespace.hpp"
#include "CompilFiles.hpp"
#include "CompilFlags.hpp"
#include <vector>
#include <string>

namespace Compil
{
    class Compilation
    {
    public:
        Compilation(struct Files files, struct Flags flags);

    private:
        /**
         * @brief   Merges builtin files and users files
         * @param files: Struct that describes all the files wanted
        */
        void _createFiles(struct Files files);

        /**
         * @brief   Setup all the flags needed for the compilation
         * @param flags: Struct that describes all the compilation flags
        */
       void _createFlags(struct Flags flags);

        // All files needs to be compiled
        std::vector<std::string> files = {};
        // Builtin files added to the compilation
        std::vector<std::string> builtinFiles = {};
        // All the flags
        std::vector<std::string> flags = {};
    };
}

#endif