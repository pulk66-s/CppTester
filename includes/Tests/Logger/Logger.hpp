#ifndef __CPPMOCHATESTER_LOGGER_LOGGER_HPP__
#define __CPPMOCHATESTER_LOGGER_LOGGER_HPP__

#include "./LoggerNamespace.hpp"
#include <string>

class Log::Logger {
public:
    /**
     * @brief   Log a title message
    */
    void title(std::string msg);

    /**
     * @brief   Log a subtitle message
    */
    void subtitle(std::string msg);

    /**
     * @brief   Log a success message
    */
    void success(std::string msg);

    /**
     * @brief   Log a warning message
    */
    void warning(std::string msg);

    /**
     * @brief   Log an error message
    */
    void error(std::string msg);

private:
    // Color codes
    const std::string RED = "\033[0;31m";
    const std::string GREEN = "\033[0;32m";
    const std::string YELLOW = "\033[0;33m";
    const std::string NC = "\033[0m";
};

#endif