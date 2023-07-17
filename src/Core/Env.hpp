#ifndef __CORE_ENV_HPP__
#define __CORE_ENV_HPP__

#include <string>
#include <cstdlib>
#include <optional>

struct Env
{
public:
    Env();
    std::optional<std::string> sourcesPath = {}; // Path of all builtin sources
};

#endif