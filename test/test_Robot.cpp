#include "test_ToyRobot.h"

#include "Position.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_Robot : public test_ToyRobot {

};

TEST_F(test_Robot, placeIfValid) {
    Robot bot {TableTop(5, 5)};
    EXPECT_FALSE(bot.placeIfValid(Position(-1, 0, NORTH)));
    EXPECT_FALSE(bot.placeIfValid(Position(0, -1, NORTH)));
    EXPECT_FALSE(bot.placeIfValid(Position(6, 5, SOUTH)));
    EXPECT_FALSE(bot.placeIfValid(Position(5, 6, SOUTH)));

    EXPECT_TRUE(bot.placeIfValid(Position(2, 2, WEST)));
    EXPECT_TRUE(bot.positionToString() == test_ToyRobot::toString(2, 2, WEST));
}

TEST_F(test_Robot, moveIfValid) {
    Robot bot {TableTop(5, 5)};
    EXPECT_TRUE(bot.placeIfValid(Position(0, 4, NORTH)));
    EXPECT_TRUE(bot.moveIfValid());
    EXPECT_TRUE(bot.positionToString() == test_ToyRobot::toString(0, 5, NORTH));
    EXPECT_FALSE(bot.moveIfValid());
}

TEST_F(test_Robot, rotateIfValid) {
    Robot bot {TableTop(5, 5)};
    EXPECT_TRUE(bot.placeIfValid(Position(3, 5, EAST)));

    EXPECT_TRUE(bot.rotateLeftIfValid());
    EXPECT_TRUE(bot.positionToString() == test_ToyRobot::toString(3, 5, NORTH));

    EXPECT_TRUE(bot.rotateRightIfValid());
    EXPECT_TRUE(bot.positionToString() == test_ToyRobot::toString(3, 5, EAST));
}
}
