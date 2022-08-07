#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandMove : public test_ToyRobot {

};

TEST_F(test_CommandMove, moveToValidPosition) {
    const auto CommandPlace = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(3, 2, WEST),
            DELIMITER
    );
    EXPECT_TRUE(CommandPlace->getCommandType() == CommandType::Place);
    EXPECT_TRUE(CommandPlace->isCommandValid());
    EXPECT_TRUE(CommandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));

    const auto CommandMove = _cmdFactory->makeCommand(
            MOVE,
            DELIMITER
    );
    EXPECT_TRUE(CommandMove->getCommandType() == CommandType::Move);
    EXPECT_TRUE(CommandMove->isCommandValid());
    EXPECT_TRUE(CommandMove->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 2, WEST));
}

TEST_F(test_CommandMove, moveToInvalidPosition) {
    const auto CommandPlace = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(DIMENSIONX, 2, EAST),
            DELIMITER
    );
    EXPECT_TRUE(CommandPlace->getCommandType() == CommandType::Place);
    EXPECT_TRUE(CommandPlace->isCommandValid());
    EXPECT_TRUE(CommandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, 2, EAST));

    const auto CommandMove = _cmdFactory->makeCommand(
            MOVE,
            DELIMITER
    );
    EXPECT_TRUE(CommandMove->getCommandType() == CommandType::Move);
    EXPECT_TRUE(CommandMove->isCommandValid());
    EXPECT_FALSE(CommandMove->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, 2, EAST));
}
}
