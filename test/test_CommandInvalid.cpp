#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandInvalid : public test_ToyRobot {

};

TEST_F(test_CommandInvalid, invalidCommand) {
    const auto CommandInvalid = _cmdFactory->makeCommand(
            "ABC",
            DELIMITER
    );
    EXPECT_TRUE(CommandInvalid->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(CommandInvalid->isCommandValid());
    EXPECT_FALSE(CommandInvalid->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}
}
