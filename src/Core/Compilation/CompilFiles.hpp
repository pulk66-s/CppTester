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
         * @param params: Program parameters
         */
        Files(Params params);

        /**
         * @brief   Get all the files from the params
         * @param params: Program parameters
         */
        Files();

        // Compilation files
        std::vector<std::string> files = {};
    };
}

#endif