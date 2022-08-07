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
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Place);
    EXPECT_TRUE(commandPlace->isCommandValid());
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, DIMENSIONY, NORTH));

    const auto commandRight = _cmdFactory->makeCommand(
            RIGHT,
            DELIMITER
    );
    EXPECT_TRUE(commandRight->getCommandType() == CommandType::Right);
    EXPECT_TRUE(commandRight->isCommandValid());
    EXPECT_TRUE(commandRight->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, DIMENSIONY, EAST));
}
}
