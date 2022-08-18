#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandInvalid : public test_ToyRobot {

};

TEST_F(test_CommandInvalid, invalidCommand) {
    const auto commandInvalid = _cmdFactory->makeCommand(
            "ABC",
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandInvalid(commandInvalid));
    EXPECT_FALSE(commandInvalid->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}
}
