#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandLeft : public test_ToyRobot {

};

TEST_F(test_CommandLeft, rotateLeft) {
    const auto commandPlace = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(3, 2, WEST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandPlace(commandPlace));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandPlace));
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));

    const auto commandLeft = _cmdFactory->makeCommand(
            LEFT,
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandLeft(commandLeft));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandLeft));
    EXPECT_TRUE(commandLeft->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, SOUTH));
}
}
