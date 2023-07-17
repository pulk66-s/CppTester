#ifndef __PARAMS_HPP__
#define __PARAMS_HPP__

#include <vector>
#include <string>
#include <optional>
#include <unordered_map>
#include <functional>

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

    /**
     * @brief   Getter for files attributes
     */
    std::vector<std::string> files() const;

    /**
     * @brief   Struct that store all the params
     */
    struct _params
    {
        std::optional<std::string> sourceDir = {};
    };

    /**
     * @brief   Getter for params structure
    */
    struct _params getParams();

private:
    /**
     * @brief   Function that verifiy if the keyword match an existing parameter
     * @param keyword: Param to check format: "flag value"
     * @param i: index of the current param
     * @param ac: total number of arguments
     * @param av: all arguments
     */
    void _matchKeyword(std::string keyword, int i, int ac, char **av);

    /**
     * @brief   Function that init the existing params
    */
   void _initDefaultParams();

    // Path of the files to compile
    std::vector<std::string> _files = {};
    // Params description
    struct _params params;
    // List of existing params
    std::unordered_map<std::string, std::function<void(int i, int ac, char **av)>> possibleParams = {};
};

#endif