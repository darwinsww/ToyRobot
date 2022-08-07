#include "Position.h"

namespace ToyRobot
{
Position::Position(int posX, int posY, const std::string &directionText)
: _posX(posX)
, _posY(posY)
, _direction(directionText) {

}

Position &Position::operator=(const Position &position) {
    if(this == &position) {
        return *this;
    }

    _posX = position._posX;
    _posY = position._posY;
    _direction = position._direction;

    return *this;
}

 bool Position::operator==(const Position& pos) const {
    return _posX == pos.getX()
        && _posY == pos.getY()
        && getDirectionType() == pos.getDirectionType()
    ;
};

int Position::getX() const {
    return _posX;
}

int Position::getY() const {
    return _posY;
}

DirectionType Position::getDirectionType() const {
    return _direction.getDirectionType();
}

bool Position::isValid() const {
    return (_posX >= 0) && (_posY >= 0) && (DirectionType::Undefined != getDirectionType());
}

Position* Position::toNorth() {
    ++_posY;
    return this;
}

Position* Position::toEast() {
    ++_posX;
    return this;
}

Position* Position::toSouth() {
    --_posY;
    return this;
}

Position* Position::toWest() {
    --_posX;
    return this;
}

Position* Position::rotateLeft() {
    _direction.rotateLeft();
    return this;
}

Position* Position::rotateRight() {
    _direction.rotateRight();
    return this;
}

std::string Position::toString() const {
    return std::to_string(_posX) + "," + std::to_string(_posY) + "," + _direction.toString();
}
}
