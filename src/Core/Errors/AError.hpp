#ifndef __CORE_ERROR_AERROR_HPP__
#define __CORE_ERROR_AERROR_HPP__

#include <exception>
#include <string>

class AError : public std::exception {
public:
    AError(const std::string& message, const std::string where) : msg(message + where) {}

    // Override the what() method to provide custom error message
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

#endif