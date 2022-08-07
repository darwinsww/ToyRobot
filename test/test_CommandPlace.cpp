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
    EXPECT_TRUE(command->getCommandType() == CommandType::Place);
    EXPECT_TRUE(command->isCommandValid());
    EXPECT_TRUE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 1, WEST));
}

TEST_F(test_CommandPlace, placeToInvalidPosition_X) {
    const auto command = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(-1, 1, WEST),
            DELIMITER
    );
    EXPECT_TRUE(command->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(command->isCommandValid());
    EXPECT_FALSE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_CommandPlace, placeToInvalidPosition_Y) {
    const auto command = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, -1, WEST),
            DELIMITER
    );
    EXPECT_TRUE(command->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(command->isCommandValid());
    EXPECT_FALSE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_CommandPlace, placeToInvalidPosition_Direction) {
    const auto command = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, 1, UNDEFINED),
            DELIMITER
    );
    EXPECT_TRUE(command->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(command->isCommandValid());
    EXPECT_FALSE(command->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_CommandPlace, placeToInvalidPositionFromValidPosition) {
    const auto commandPlaceToValidPos = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(3, 2, WEST),
            DELIMITER
    );
    EXPECT_TRUE(commandPlaceToValidPos->getCommandType() == CommandType::Place);
    EXPECT_TRUE(commandPlaceToValidPos->isCommandValid());
    EXPECT_TRUE(commandPlaceToValidPos->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));

    const auto commandPlaceToInvalidPos = _cmdFactory->makeCommand(
            PLACE + " " + test_ToyRobot::toString(1, -1, WEST),
            DELIMITER
    );
    EXPECT_TRUE(commandPlaceToInvalidPos->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(commandPlaceToInvalidPos->isCommandValid());
    EXPECT_FALSE(commandPlaceToInvalidPos->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 2, WEST));
}
}
