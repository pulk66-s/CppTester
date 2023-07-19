#include "./CoreDatas.hpp"

std::string coreData::getIncludePath()
{
    std::string prefix = "";

    if (this->env.sourcesPath) {
        prefix = *this->env.sourcesPath;
    } else if (params.getParams().sourceDir) {
        prefix = *params.getParams().sourceDir;
    } else {
        prefix = "/usr/include/CppTester";
    }
    return prefix;
}

std::string coreData::getSourcesPath()
{
    std::string prefix = "";

    if (this->env.sourcesPath) {
        prefix = *this->env.sourcesPath;
    } else if (params.getParams().sourceDir) {
        prefix = *params.getParams().sourceDir;
    } else {
        prefix = "/lib/CppTester";
    }
    return prefix;
}

coreData::coreData(int ac, char **av): params(ac, av) {}
