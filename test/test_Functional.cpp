#include "test_ToyRobot.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_Functional : public test_ToyRobot {
protected:
    void SetUp() override {
        test_ToyRobot::SetUp();

        _robot = std::make_shared<Robot>(TableTop {DIMENSIONX, DIMENSIONY});
        _placeCommand = std::make_shared<CommandPlace>(_robot);
        _moveCommand = std::make_shared<CommandMove>(_robot);
        _leftCommand = std::make_shared<CommandLeft>(_robot);
        _rightCommand = std::make_shared<CommandRight>(_robot);
        _reportCommand = std::make_shared<CommandReport>(_robot);
        _invalidCommand = std::make_shared<CommandInvalid>(_robot);
    }

    void TearDown() override {
        test_ToyRobot::TearDown();

        _robot.reset();
        _placeCommand.reset();
        _moveCommand.reset();
        _leftCommand.reset();
        _rightCommand.reset();
        _reportCommand.reset();
        _invalidCommand.reset();
    }

    void executePlaceCommand(const Position& position) {
        _placeCommand->setPosition(position);
        _placeCommand->executeCommand();
    }

protected:
    std::shared_ptr<Robot> _robot;
    std::shared_ptr<CommandPlace> _placeCommand;
    std::shared_ptr<CommandMove> _moveCommand;
    std::shared_ptr<CommandLeft> _leftCommand;
    std::shared_ptr<CommandRight> _rightCommand;
    std::shared_ptr<CommandReport> _reportCommand;
    std::shared_ptr<CommandInvalid> _invalidCommand;
};

// Place
TEST_F(test_Functional, placeToInvalidX) {
    executePlaceCommand(Position(-1,4,NORTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_Functional, placeToInvalidY) {
    executePlaceCommand(Position(1,-4,NORTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_Functional, placeToInvalidDirection) {
    executePlaceCommand(Position(1,4,UNDEFINED));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_Functional, validPlace) {
    executePlaceCommand(Position(2,3,NORTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));
}

TEST_F(test_Functional, validPlaceTwice) {
    executePlaceCommand(Position(2,3,NORTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));

    executePlaceCommand(Position(1,4,SOUTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1,4,SOUTH));
}

TEST_F(test_Functional, placeValidThenInvalid) {
    executePlaceCommand(Position(2,3,NORTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));

    executePlaceCommand(Position(DIMENSIONX + 1,4,SOUTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2,3,NORTH));
}

TEST_F(test_Functional, placeInvalidThenValid) {
    executePlaceCommand(Position(DIMENSIONX + 1,4,SOUTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1,-1,UNDEFINED));

    executePlaceCommand(Position(2,3,NORTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));
}

TEST_F(test_Functional, placeMultipleTimes) {
    executePlaceCommand(Position(-1,4,SOUTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1,-1,UNDEFINED));

    executePlaceCommand(Position(2,3,NORTH));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));

    executePlaceCommand(Position(0,1,EAST));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 1, EAST));

    executePlaceCommand(Position(2,DIMENSIONY + 1,WEST));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 1, EAST));
}

// Rotate (Left & Right)
TEST_F(test_Functional, invalidRotateLeftWithoutPlacing) {
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_Functional, invalidRotateRightWithoutPlacing) {
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_Functional, validRotateLeft) {
    executePlaceCommand(Position(0,0,NORTH));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 0, WEST));
}

TEST_F(test_Functional, validRotateRight) {
    executePlaceCommand(Position(2,3,NORTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, EAST));
}

TEST_F(test_Functional, rotateLeftMultipleTimes) {
    executePlaceCommand(Position(2,3,NORTH));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, WEST));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, SOUTH));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, EAST));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, WEST));
}

TEST_F(test_Functional, rotateRightMultipleTimes) {
    executePlaceCommand(Position(2,3,NORTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, EAST));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, SOUTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, WEST));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, EAST));
}

TEST_F(test_Functional, mixedRotation) {
    executePlaceCommand(Position(2,3,NORTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, EAST));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, EAST));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, SOUTH));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, EAST));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, SOUTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, WEST));
}

// Move
TEST_F(test_Functional, invalidMoveWithoutPlacing) {
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(-1, -1, UNDEFINED));
}

TEST_F(test_Functional, validMoveNorth) {
    executePlaceCommand(Position(0,0,NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 1, NORTH));
}

TEST_F(test_Functional, validMoveEast) {
    executePlaceCommand(Position(2,3,EAST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 3, EAST));
}

TEST_F(test_Functional, validMoveSouth) {
    executePlaceCommand(Position(2,3,SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 2, SOUTH));
}

TEST_F(test_Functional, validMoveWest) {
    executePlaceCommand(Position(2,3,WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 3, WEST));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromSouthWestToWest) {
    executePlaceCommand(Position(0,0,WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 0, WEST));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromSouthWestToSouth) {
    executePlaceCommand(Position(0,0,SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 0, SOUTH));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromNorthWestToWest) {
    executePlaceCommand(Position(0,DIMENSIONY,WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, DIMENSIONY, WEST));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromNorthWestToNorth) {
    executePlaceCommand(Position(0,DIMENSIONY,NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, DIMENSIONY, NORTH));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromNorthEastToNorth) {
    executePlaceCommand(Position(DIMENSIONX,DIMENSIONY,NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, DIMENSIONY, NORTH));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromNorthEastToEast) {
    executePlaceCommand(Position(DIMENSIONX,DIMENSIONY,EAST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, DIMENSIONY, EAST));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromSouthEastToSouth) {
    executePlaceCommand(Position(DIMENSIONX,0,SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, 0, SOUTH));
}

TEST_F(test_Functional, invalidMoveOutOfTableFromSouthEastToEast) {
    executePlaceCommand(Position(DIMENSIONX,0,EAST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, 0, EAST));
}

TEST_F(test_Functional, multipleMoveToNorth) {
    executePlaceCommand(Position(2,2,NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 4, NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 4, NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 4, NORTH));
}

TEST_F(test_Functional, multipleMoveToEast) {
    executePlaceCommand(Position(2,3,EAST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 3, EAST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(4, 3, EAST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(4, 3, EAST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(4, 3, EAST));
}

TEST_F(test_Functional, multipleMoveToSouth) {
    executePlaceCommand(Position(2,3,SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 2, SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 1, SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 0, SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 0, SOUTH));
}

TEST_F(test_Functional, multipleMoveToWest) {
    executePlaceCommand(Position(3,3,WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 3, WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 3, WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 3, WEST));
}

// Combined Commands
TEST_F(test_Functional, commandsCombined) {
    executePlaceCommand(Position(1,2,EAST));
    _moveCommand->executeCommand();
    _moveCommand->executeCommand();
    _leftCommand->executeCommand();
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 3, NORTH));
}

TEST_F(test_Functional, commandsCombinedRandomly) {
    _moveCommand->executeCommand();
    _rightCommand->executeCommand();
    executePlaceCommand(Position(3,3,WEST));
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(3, 3, WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, WEST));
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 3, SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 2, SOUTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(2, 2, WEST));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 2, WEST));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 2, NORTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 3, NORTH));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 3, EAST));
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 3, SOUTH));
    _moveCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(1, 2, SOUTH));
}

TEST_F(test_Functional, commandsCombinedVisitAllTabletopEdges) {
    executePlaceCommand(Position(0,0,NORTH));
    for(int i = 0; i <= DIMENSIONY+2; ++i) {
        _moveCommand->executeCommand();
    }
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0,DIMENSIONY,EAST));
    for(int i = 0; i <= DIMENSIONY+2; ++i) {
        _moveCommand->executeCommand();
    }
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX,DIMENSIONY,SOUTH));
    for(int i = 0; i <= DIMENSIONY+2; ++i) {
        _moveCommand->executeCommand();
    }
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(DIMENSIONX, 0, WEST));
    for(int i = 0; i <= DIMENSIONY+2; ++i) {
        _moveCommand->executeCommand();
    }
    _rightCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0, 0, NORTH));
    for(int i = 0; i <= DIMENSIONY+2; ++i) {
        _moveCommand->executeCommand();
    }
    _leftCommand->executeCommand();
    EXPECT_TRUE(_robot->positionToString() == test_ToyRobot::toString(0,DIMENSIONY,WEST));
}
}
