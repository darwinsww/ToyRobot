#include "Direction.h"

namespace ToyRobot
{
std::map<std::string, DirectionType> createDirectionsTextToTypeMap()
{
    std::map<std::string, DirectionType> directionsTextToTypeMap;
    directionsTextToTypeMap["NORTH"] = DirectionType::North;
    directionsTextToTypeMap["SOUTH"] = DirectionType::South;
    directionsTextToTypeMap["WEST"] = DirectionType::West;
    directionsTextToTypeMap["EAST"] = DirectionType::East;
    directionsTextToTypeMap["UNDEFINED"] = DirectionType::Undefined;

    return directionsTextToTypeMap;
}
const std::map<std::string, DirectionType> Direction::_directionsTextToTypeMap = createDirectionsTextToTypeMap();

Direction::Direction(const std::string &directionText) {
    const auto iterator = _directionsTextToTypeMap.find(directionText);
    if(_directionsTextToTypeMap.end() != iterator) {
        _directionType = iterator->second;
    }
    else {
        _directionType = DirectionType::Undefined;
    }
}

DirectionType Direction::getDirectionType() const {
    return _directionType;
}

void Direction::setDirectionType(const DirectionType directionType) {
    _directionType = directionType;
}

void Direction::rotateLeft() {
    int currentDirection = static_cast<int>(_directionType);
    int newDirection = currentDirection << 1;
    if(newDirection > static_cast<int>(DirectionType::East)) {
        _directionType = DirectionType::North;
    }
    else {
        _directionType = static_cast<DirectionType>(newDirection);
    }
}

void Direction::rotateRight() {
    int currentDirection = static_cast<int>(_directionType);
    int newDirection = currentDirection >> 1;
    if(newDirection < static_cast<int>(DirectionType::North)) {
        _directionType = DirectionType::East;
    }
    else {
        _directionType = static_cast<DirectionType>(newDirection);
    }
}

std::string Direction::toString() const {
    for(const auto &mapElement : _directionsTextToTypeMap) {
        if(mapElement.second == _directionType) {
            return mapElement.first;
        }
    }

    return {};
}
}
