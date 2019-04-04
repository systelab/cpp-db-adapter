#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

#include "DbAdapterTestUtilities/Mocks/MockDatabase.h"


int main(int argc, char *argv[])
{
    systelab::db::test_utility::MockDatabase database;
    std::cout << "DB adapter test utilities work as expected" << std::endl;

    return 0;
}
