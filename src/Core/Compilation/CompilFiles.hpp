#ifndef __COMPILATION_COMPILFILES_HPP__
#define __COMPILATION_COMPILFILES_HPP__

#include "./../Params.hpp"
#include "./CompilationNamespace.hpp"

namespace Compil
{
    struct Files
    {
    public:
        /**
         * @brief   Get all the files from the params
         */
        Files(Params params);

        // Compilation files
        std::vector<std::string> files = {};
    };
}

#endif