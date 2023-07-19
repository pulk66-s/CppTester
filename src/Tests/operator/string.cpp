#include "Tests/Assert/operator/string.hpp"

bool operator==(const std::string &a, const std::string &b)
{
    return a.compare(b) == 0;
}