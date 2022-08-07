#include "Robot.h"
#include "Direction.h"

#include <iostream>

namespace ToyRobot
{
Robot::Robot(const TableTop &tableTop)
: _tableTop(tableTop) {

}

bool Robot::isPosValid(const Position &position) {
    return _tableTop.isOnTable(position.getX(), position.getY())
        && position.isValid();
}

bool Robot::setPositionIfValid(const Position &newPosition) {
    if(!isPosValid(newPosition)) {
        return false;
    }

    _position = newPosition;
    return true;
}

bool Robot::moveIfValid() {
    if(!isPosValid(_position)) {
        return false;
    }

    Position newPosition = _position;
    switch(_position.getDirectionType()) {
        case DirectionType::North: {
            newPosition.toNorth();
            break;
        }
        case DirectionType::East: {
            newPosition.toEast();
            break;
        }
        case DirectionType::South: {
            newPosition.toSouth();
            break;
        }
        case DirectionType::West: {
            newPosition.toWest();
            break;
        }
        case DirectionType::Undefined:
            return false;
    }

    return setPositionIfValid(newPosition);
}

bool Robot::placeIfValid(const Position &newPosition) {
    if(!isPosValid(newPosition)) {
        return false;
    }

    _position = newPosition;
    return true;
}

bool Robot::rotateLeftIfValid() {
    if(!isPosValid(_position)) {
        return false;
    }

    _position.rotateLeft();
    return true;
}

bool Robot::rotateRightIfValid() {
    if(!isPosValid(_position)) {
        return false;
    }

    _position.rotateRight();
    return true;
}

void Robot::reportPosition() const {
    std::cout << positionToString() << std::endl;
}

std::string Robot::positionToString() const {
    return _position.toString();
}
}
