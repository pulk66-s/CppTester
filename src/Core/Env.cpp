#include "./Env.hpp"
#include "./Errors/EnvError.hpp"
#include <iostream>

Env::Env()
{
    const char *v = std::getenv("CPP_MOCHA_SRC_DIR");

    if (v) {
        this->sourcesPath = v;
    }
}