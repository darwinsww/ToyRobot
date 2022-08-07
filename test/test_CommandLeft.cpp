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
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Place);
    EXPECT_TRUE(commandPlace->isCommandValid());
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));

    const auto commandLeft = _cmdFactory->makeCommand(
            LEFT,
            DELIMITER
    );
    EXPECT_TRUE(commandLeft->getCommandType() == CommandType::Left);
    EXPECT_TRUE(commandLeft->isCommandValid());
    EXPECT_TRUE(commandLeft->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, SOUTH));
}
}
