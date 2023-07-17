#include "./To.hpp"

namespace Tests::Assert
{
    To::To(void *value) : be(value)
    {
        this->value = value;
    }
}