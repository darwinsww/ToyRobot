#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_CommandFactory : public test_ToyRobot {

};

TEST_F(test_CommandFactory, invalidString) {
    const auto commandPlace = _cmdFactory->makeCommand(
            "abcd",
            DELIMITER
    );
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(commandPlace->isCommandValid());
}

TEST_F(test_CommandFactory, invalidDoublePosition) {
    const auto commandPlace = _cmdFactory->makeCommand(
            "place 1.1,2,north",
            DELIMITER
    );
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(commandPlace->isCommandValid());
}

TEST_F(test_CommandFactory, invalidNegativePosition) {
    const auto commandPlace = _cmdFactory->makeCommand(
            "place 2,-3,north",
            DELIMITER
    );
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(commandPlace->isCommandValid());
}

TEST_F(test_CommandFactory, validPositionWithWhitespaceInBothEnds) {
    const auto commandPlace = _cmdFactory->makeCommand(
            "    place 4,0,north    ",
            DELIMITER
    );
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Place);
    EXPECT_TRUE(commandPlace->isCommandValid());
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(4, 0, NORTH));
}

TEST_F(test_CommandFactory, invalidPositionWithWhitespaceInTheMiddle) {
    const auto commandPlace = _cmdFactory->makeCommand(
            "place 1, 3 ,north",
            DELIMITER
    );
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Invalid);
    EXPECT_FALSE(commandPlace->isCommandValid());
}

TEST_F(test_CommandFactory, validPositionMixedUpperLowerCase) {
    const auto commandPlace = _cmdFactory->makeCommand(
            "pLAce 1,3,sOuTH",
            DELIMITER
    );
    EXPECT_TRUE(commandPlace->getCommandType() == CommandType::Place);
    EXPECT_TRUE(commandPlace->isCommandValid());
    EXPECT_TRUE(commandPlace->executeCommand());
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 3, SOUTH));
}
}
