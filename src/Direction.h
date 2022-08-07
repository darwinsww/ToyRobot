#ifndef TOYROBOT_DIRECTION_H
#define TOYROBOT_DIRECTION_H

#include <string>
#include <map>

namespace ToyRobot
{
enum class DirectionType
{
    Undefined = 0,
    North = 1 << 0,
    West = 1 << 1,
    South = 1 << 2,
    East = 1 << 3,
};

class Direction {
public:
    Direction() = default;
    explicit Direction(const std::string &directionText);

    DirectionType getDirectionType() const;
    void setDirectionType(DirectionType directionType);

    void rotateLeft();
    void rotateRight();

    std::string toString() const;

private:
    static const std::map<std::string, DirectionType> _directionsTextToTypeMap;

    DirectionType _directionType {DirectionType::Undefined};
};
}

#endif //TOYROBOT_DIRECTION_H
