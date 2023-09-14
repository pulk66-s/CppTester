#include "Tests/TestSuite.hpp"
#include <iostream>

int main()
{
    int nbFails = 0;
    try {
        nbFails = Tests::TestSuite::run();
    } catch (std::exception &err) {
        std::cout << "Error" << std::endl;
        std::cerr << err.what() << std::endl;
        return 84;
    }

    return nbFails;
}