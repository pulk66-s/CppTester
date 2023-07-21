#include "Tests/Logger/Logger.hpp"
#include <iostream>

namespace Log {
    void Logger::title(std::string msg) {
        std::size_t msgLength = msg.length();

        std::cout << GREEN;
        for (std::size_t i = 0; i < msgLength + 4; i++) {
            std::cout << "=";
        }
        std::cout << std::endl << "= " << msg << " =" << std::endl;
        for (std::size_t i = 0; i < msgLength + 4; i++) {
            std::cout << "=";
        }
        std::cout << NC << std::endl;
    }

    void Logger::subtitle(std::string msg) {
        std::cout << GREEN << "[SUBTITLE] " << msg << NC << std::endl;
    }

    void Logger::success(std::string msg) {
        std::cout << GREEN << "[SUCCESS] " << msg << NC << std::endl;
    }

    void Logger::warning(std::string msg) {
        std::cout << YELLOW << "[WARNING] " << msg << NC << std::endl;
    }

    void Logger::error(std::string msg) {
        std::cout << RED << "[ERROR] " << msg << NC << std::endl;
    }

}