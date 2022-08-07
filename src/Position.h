#ifndef TOYROBOT_POSITION_H
#define TOYROBOT_POSITION_H

#include "Direction.h"

namespace ToyRobot
{
class Position {
public:
    Position() = default;
    Position(int posX, int posY, const std::string &directionText);
    Position& operator=(const Position &position);
    bool operator==(const Position& pos) const;

    int getX() const;
    int getY() const;
    DirectionType getDirectionType() const;

    bool isValid() const;

    Position* toNorth();
    Position* toEast();
    Position* toSouth();
    Position* toWest();

    Position* rotateLeft();
    Position* rotateRight();

    std::string toString() const;

private:
    int _posX {-1};
    int _posY {-1};
    Direction _direction;
};
}

#endif //TOYROBOT_POSITION_H
