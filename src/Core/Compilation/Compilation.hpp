#ifndef __COMPILATION_COMPILATION_HPP__
#define __COMPILATION_COMPILATION_HPP__

#include "CompilationNamespace.hpp"
#include "CompilFiles.hpp"
#include "CompilFlags.hpp"
#include "Gpp.hpp"
#include "./../CoreDatas.hpp"
#include <vector>
#include <string>

namespace Compil
{
    class Compilation
    {
    public:
        /**
         * @brief   Initialize the compilation process
         * @param files: files to compile
         * @param builtinFiles: files given by the software
         * @param flags: flags to compile
        */
        Compilation(
            struct Files files,
            struct Files builtinFiles, 
            struct Flags flags, 
            struct coreData datas
        );

        /**
         * @brief   Destructor of the Compilation
         * It clean all the created ressources
        */
        ~Compilation();

        /**
         * @brief   Run the compilation
        */
        void run(void);

        /**
         * @brief   Run the compiled prgm
        */
        int runprgm(void);

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

       /**
        * @brief    Setup of the builtin files
        * @param builtinFiles: All the builtin files, not the user one
       */
       void _setupBuiltinFiles(struct Files builtinFiles);

        // All files needs to be compiled
        std::vector<std::string> files = {};
        // Builtin files added to the compilation
        std::vector<std::string> builtinFiles = {};
        // All the flags
        std::vector<std::string> flags = {};

        // Compilation system
        Gpp gpp;

        // Core datas
        struct coreData coreDatas;
    };
}

#endif