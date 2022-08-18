#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandMove : public test_ToyRobot {

};

TEST_F(test_CommandMove, moveToValidPosition) {
    const auto commandPlace = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(3, 2, WEST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandPlace(commandPlace));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandPlace));
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));

    const auto commandMove = _cmdFactory->makeCommand(
            MOVE,
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandMove(commandMove));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandMove));
    EXPECT_TRUE(commandMove->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 2, WEST));
}

TEST_F(test_CommandMove, moveToInvalidPosition) {
    const auto commandPlace = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(DIMENSIONX, 2, EAST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandPlace(commandPlace));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandPlace));
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, 2, EAST));

    const auto commandMove = _cmdFactory->makeCommand(
            MOVE,
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandMove(commandMove));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandMove));
    EXPECT_FALSE(commandMove->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, 2, EAST));
}
}
