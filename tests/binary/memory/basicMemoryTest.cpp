#include <CppTester/Tests.hpp>
#include <CppTester/Assert.hpp>
#include <iostream>
#include <cstdlib>

TestBinary(boot_sector, boot_number, bin/boot.bin) {
    expectBin(bin).memory(510).to.be.equal(0x55);
    expectBin(bin).memory(511).to.be.equal(0xAA);
}