#ifndef __CORE_HPP__
#define __CORE_HPP__

#include "./Params.hpp"
#include "./Env.hpp"

/**
 * @brief Core class
 * This class Initialize the project
 * And run the differents modules
 */
class Core
{
public:
    /**
     * @brief Construct the Core of the project
     * @param ac Number of arguments
     * @param av Arguments
    */
    Core(int ac, char **av);

    /**
     * @brief Destroy the Core of the project
     * And free the memory
    */
    ~Core();

private:
    // Params of the project
    Params params;
    // Environment of the project
    Env env;
};

#endif