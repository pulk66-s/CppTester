#ifndef __CORE_HPP__
#define __CORE_HPP__

#include "./Params.hpp"
#include "./Env.hpp"
#include "./CoreDatas.hpp"

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

    /**
     * @brief   Get the path of the include folder
     * @return: the path of the include folder
    */
    static std::string getIncludePath();

    /**
     * @brief   Get the nb of failure
     * @return: the nb of failure
    */
    int getNbFailure() { return this->nbFailure; };

private:
    struct coreData datas;
    int nbFailure = 0;
};

#endif