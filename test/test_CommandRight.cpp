#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandRight : public test_ToyRobot {

};

TEST_F(test_CommandRight, rotateRight) {
    const auto commandPlace = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(2, DIMENSIONY, NORTH),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandPlace(commandPlace));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandPlace));
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, DIMENSIONY, NORTH));

    const auto commandRight = _cmdFactory->makeCommand(
            RIGHT,
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandRight(commandRight));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandRight));
    EXPECT_TRUE(commandRight->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, DIMENSIONY, EAST));
}
}
