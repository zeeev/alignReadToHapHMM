#include <stdio.h>
#include "gtest/gtest.h"
#include "test/phredUtilsTests.h"

GTEST_API_ int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
