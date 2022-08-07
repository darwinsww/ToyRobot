#include "CommandPlace.h"

#include <cassert>

namespace ToyRobot
{
CommandPlace::CommandPlace(std::shared_ptr<Robot> &robot)
: Command(robot) {

}

bool CommandPlace::executeCommand() {
    assert(nullptr != _robot);
    return _robot->placeIfValid(_position);
}

CommandType CommandPlace::getCommandType() const {
    return CommandType::Place;
}

void CommandPlace::setPosition(const Position &newPosition) {
    _position = newPosition;
}
}
