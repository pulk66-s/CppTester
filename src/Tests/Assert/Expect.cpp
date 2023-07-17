#include "./Expect.hpp"

namespace Tests::Assert {
    struct Expect expect(void *value)
    {
        return Tests::Assert::Expect(value);
    }

    Expect::Expect(void *value): to(value)
    {
        this->value = value;
    }
}