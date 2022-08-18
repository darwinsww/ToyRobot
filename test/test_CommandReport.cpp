#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandReport : public test_ToyRobot {

};

TEST_F(test_CommandReport, reportCommand) {
    const auto commandPlace = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, DIMENSIONY, EAST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandPlace(commandPlace));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandPlace));
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, DIMENSIONY, EAST));

    const auto commandReport = _cmdFactory->makeCommand(
            REPORT,
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandReport(commandReport));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandReport));
    EXPECT_TRUE(commandReport->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, DIMENSIONY, EAST));
}
}
