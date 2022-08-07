#include "test_ToyRobot.h"

#include "Direction.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_Direction : public test_ToyRobot {

};

TEST_F(test_Direction, construction) {
    Direction dir1;
    EXPECT_TRUE(DirectionType::Undefined == dir1.getDirectionType());

    Direction dir2;
    dir2.setDirectionType(DirectionType::East);

    dir1 = dir2;
    EXPECT_TRUE(DirectionType::East == dir1.getDirectionType());
}

TEST_F(test_Direction, assignment) {
    Direction dir1;
    Direction dir2;
    dir2.setDirectionType(DirectionType::East);

    dir1 = dir2;
    EXPECT_TRUE(DirectionType::East == dir1.getDirectionType());
}

TEST_F(test_Direction, accessMemberVariables) {
    Direction dir;
    dir.setDirectionType(DirectionType::West);
    EXPECT_TRUE(DirectionType::West == dir.getDirectionType());
}

TEST_F(test_Direction, rotation) {
    Direction dir;
    dir.setDirectionType(DirectionType::West);

    dir.rotateLeft();
    EXPECT_TRUE(DirectionType::South == dir.getDirectionType());

    dir.rotateRight();
    EXPECT_TRUE(DirectionType::West == dir.getDirectionType());
}

TEST_F(test_Direction, toString) {
    Direction dir;
    dir.setDirectionType(DirectionType::South);
    EXPECT_TRUE(dir.toString() == SOUTH);
}
}
