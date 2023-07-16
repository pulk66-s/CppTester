#ifndef __PARAMS_HPP__
#define __PARAMS_HPP__

#include <vector>
#include <string>

/**
 * @brief   This file contains the definition of the Params class.
 * It parses and stores the parameters of the program.
 */
class Params
{
public:
    /**
     * @brief   Constructor of the Params class.
     * It parses the parameters of the program.
     * @param ac    Number of arguments.
     * @param av    Arguments.
    */
    Params(int ac, char **av);

private:
    // Path of the files to compile
    std::vector<std::string> files;
};

#endif