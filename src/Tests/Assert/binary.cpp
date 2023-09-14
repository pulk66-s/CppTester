#include "Assert.hpp"
#include "Tests.hpp"

/**
 * @brief   Entry of the expect function
 * @param binary: The binary that need to be tested
 * @return: Expect object
 *
 */
struct Binary::Expect expectBin(std::shared_ptr<Binary::Bin> binary)
{
    return binary->expect();
}
