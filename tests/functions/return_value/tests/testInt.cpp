#include "./../int.hpp"
#include <Tests.hpp>
#include <Assert.hpp>
#include <iostream>

Test(test_int, basic) {
    expect(add(3, 4)).to.be.equal(7);
}

Test(test_int, should_crash) {
    try {
        expect(add(3, 4)).to.be.equal(8);
    } catch (std::exception &err) {
        return;
    }
    throw std::exception();
}
