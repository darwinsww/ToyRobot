#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_TableTop : public test_ToyRobot {

};

TEST_F(test_TableTop, isOnTable) {
    TableTop tableTop(5, 5);

    EXPECT_TRUE(tableTop.isOnTable(0, 0));
    EXPECT_TRUE(tableTop.isOnTable(0, 5));
    EXPECT_TRUE(tableTop.isOnTable(5, 0));
    EXPECT_TRUE(tableTop.isOnTable(5, 5));
    EXPECT_TRUE(tableTop.isOnTable(2, 2));

    EXPECT_FALSE(tableTop.isOnTable(-1, 0));
    EXPECT_FALSE(tableTop.isOnTable(0, -1));
    EXPECT_FALSE(tableTop.isOnTable(6, 5));
    EXPECT_FALSE(tableTop.isOnTable(5, 6));
}
}
