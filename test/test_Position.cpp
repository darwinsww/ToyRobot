#include "test_ToyRobot.h"

#include "Position.h"
#include "Direction.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_Position : public test_ToyRobot {

};

TEST_F(test_Position, construction) {
    Position pos1;
    Position pos2{-1, -1, UNDEFINED};
    EXPECT_TRUE(pos1 == pos2);
}

TEST_F(test_Position, assignment) {
    Position pos1{3, 2, NORTH};
    Position pos2 = pos1;
    EXPECT_TRUE(pos1 == pos2);
}

TEST_F(test_Position, accessMemberVariables) {
    Position pos1{3, 5, NORTH};
    EXPECT_TRUE(pos1.getX() == 3);
    EXPECT_TRUE(pos1.getY() == 5);
    EXPECT_TRUE(pos1.getDirectionType() == DirectionType::North);

    Position pos2{-1, 10000, "nOrTh"};
    EXPECT_TRUE(pos2.getX() == -1);
    EXPECT_TRUE(pos2.getY() == 10000);
    EXPECT_TRUE(pos2.getDirectionType() == DirectionType::Undefined);
}

TEST_F(test_Position, isValid) {
    Position validPos1{3, 5, NORTH};
    EXPECT_TRUE(validPos1.isValid());

    Position validPos2{0, 0, EAST};
    EXPECT_TRUE(validPos2.isValid());

    Position invalidPos1{-1, 0, SOUTH};
    EXPECT_FALSE(invalidPos1.isValid());

    Position invalidPos2{0, -1, WEST};
    EXPECT_FALSE(invalidPos2.isValid());

    Position invalidPos3{0, 0, UNDEFINED};
    EXPECT_FALSE(invalidPos3.isValid());
}

TEST_F(test_Position, moveAndRotate) {
    Position pos{3, 5, NORTH};

    EXPECT_TRUE(*pos.toNorth() == Position(3, 6, NORTH));
    EXPECT_TRUE(*pos.toSouth() == Position(3, 5, NORTH));
    EXPECT_TRUE(*pos.toEast() == Position(4, 5, NORTH));
    EXPECT_TRUE(*pos.toWest() == Position(3, 5, NORTH));

    EXPECT_TRUE(*pos.rotateLeft() == Position(3, 5, WEST));
    EXPECT_TRUE(*pos.rotateRight() == Position(3, 5, NORTH));
}

TEST_F(test_Position, toString) {
    Position pos{1, 7, SOUTH};
    EXPECT_TRUE(("1,7," + SOUTH) == pos.toString());
}
}
