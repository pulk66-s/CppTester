#ifndef __CORE_COREDATAS_HPP__
#define __CORE_COREDATAS_HPP__

#include <string>
#include "./Params.hpp"
#include "./Env.hpp"

struct coreData
{
public:
    coreData(int ac, char **av);
    std::string getIncludePath();
    std::string getSourcesPath();
    // Params of the project
    Params params;
    // Environment of the project
    Env env;
};

#endif