/**
 * @package C++ 
 * @file Params.cpp
 * @brief Params Class
 * Params implementation of the project. It parse all the parameters of the program.
*/

#include "./Params.hpp"
#include "./Errors/ParamError.hpp"
#include <iostream>

void Params::_initDefaultParams()
{
    this->possibleParams = {
        {
            "sources", [&](int *i, int ac, char **av) {
                std::cout << "detected sources" << std::endl;
                if (*i == ac) {
                    throw ParamError("--sources flag miss the value", __FILE__);
                }
                this->params.sourceDir = av[*i + 1];
                (*i)++;
            }
        },
        {
            "includes", [&](int *i, int ac, char **av) {
                std::cout << "detected includes" << std::endl;
                if (*i == ac) {
                    throw ParamError("--includes flag miss the value", __FILE__);
                }
                this->params.includes.push_back(av[*i + 1]);
                (*i)++;
            }
        },
        {
            "libs", [&](int *i, int ac, char **av) {
                std::cout << "detected libs" << std::endl;
                if (*i == ac) {
                    throw ParamError("--libs flag miss the value", __FILE__);
                }
                this->params.libs.push_back(av[*i + 1]);
                (*i)++;
            }
        },
        {
            "debug", [&](__attribute__((unused))int *i, __attribute__((unused))int ac, __attribute__((unused))char **av) {
                std::cout << "detected debug" << std::endl;
                this->params.debug = true;
            }
        }
    };
}

void Params::_matchKeyword(std::string keyword, int *i, int ac, char **av)
{
    if (this->possibleParams.find(keyword) == this->possibleParams.end()) {
        throw ParamError(("keyword " + keyword + " doesn't exists").c_str(), __FILE__);
    }
    this->possibleParams[keyword](i, ac, av);
}

Params::Params(int ac, char **av) {
    this->_initDefaultParams();
    for (int i = 1; i < ac; i++) {
        std::string param = av[i];

        if (param[0] == '-') {
            std::string keyword = param[1] == '-' ? &param[2] : &param[1];

            this->_matchKeyword(keyword, &i, ac, av);
        } else {
            this->_files.push_back(av[i]);
        }
    }
}

std::vector<std::string> Params::files() const {
    return this->_files;
}

struct Params::_params Params::getParams() {
    return this->params;
}