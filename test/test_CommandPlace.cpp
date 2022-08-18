#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandPlace : public test_ToyRobot {

};

TEST_F(test_CommandPlace, placeToValidPosition) {
    const auto command = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, 1, WEST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandPlace(command));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(command));
    EXPECT_TRUE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 1, WEST));
}

TEST_F(test_CommandPlace, placeToInvalidPosition_X) {
    const auto command = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(-1, 1, WEST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandInvalid(command));
    EXPECT_FALSE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_CommandPlace, placeToInvalidPosition_Y) {
    const auto command = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, -1, WEST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandInvalid(command));
    EXPECT_FALSE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_CommandPlace, placeToInvalidPosition_Direction) {
    const auto command = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, 1, UNDEFINED),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandInvalid(command));
    EXPECT_FALSE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_CommandPlace, placeToInvalidPositionFromValidPosition) {
    const auto commandPlaceToValidPos = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(3, 2, WEST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandPlace(commandPlaceToValidPos));
    EXPECT_FALSE(test_ToyRobot::isCommandInvalid(commandPlaceToValidPos));
    EXPECT_TRUE(commandPlaceToValidPos->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));

    const auto commandPlaceToInvalidPos = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, -1, WEST),
            DELIMITER
    );
    EXPECT_TRUE(test_ToyRobot::isCommandInvalid(commandPlaceToInvalidPos));
    EXPECT_FALSE(commandPlaceToInvalidPos->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));
}
}
