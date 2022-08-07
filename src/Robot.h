#ifndef TOYROBOT_ROBOT_H
#define TOYROBOT_ROBOT_H

#include "TableTop.h"
#include "Position.h"

namespace ToyRobot
{
class Robot {
public:
    explicit Robot(const TableTop &tableTop);

    bool moveIfValid();
    bool placeIfValid(const Position &newPosition);
    bool rotateLeftIfValid();
    bool rotateRightIfValid();
    void reportPosition() const;

    std::string positionToString() const;

private:
    bool isPosValid(const Position &position);
    bool setPositionIfValid(const Position &newPosition);

private:
    TableTop _tableTop;
    Position _position;
};
}

#endif //TOYROBOT_ROBOT_H
