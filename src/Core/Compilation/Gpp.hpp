#ifndef __CORE_COMPILATION_GPP_HPP__
#define __CORE_COMPILATION_GPP_HPP__

#include <vector>
#include <string>
#include <cstdlib>

namespace Compil
{
    /**
     * @brief   This class Handles all G++ compiler features
     */
    class Gpp
    {
    public:
        /**
         * @brief Execute the g++ commands;
         * @param files: All the files for the compilation
         * @param flags: All the flags for the compilation
         */
        void run(std::vector<std::string> files, std::vector<std::string> flags);

    private:
        /**
         * @brief   Create the full command that will be launched
         * @param files: All the files for the compilation
         * @param flags: All the flags for the compilation
         * @return std::string: The command
        */
        std::string _formatCommand(std::vector<std::string> files, std::vector<std::string> flags);

        // Compiler used for compilation
        std::string compiler = "g++";
    };
}

#endif