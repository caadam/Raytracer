#include "test.h"

Test::~Test() {}
Test::Test(int value)
{
    testInt = value;
}

void Test::set(int value) {
    testInt = value;
}

