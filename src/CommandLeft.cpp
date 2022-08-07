#include "CommandLeft.h"

#include <cassert>

namespace ToyRobot
{
CommandLeft::CommandLeft(std::shared_ptr<Robot> &robot)
: Command(robot) {

}

bool CommandLeft::executeCommand() {
    assert(nullptr != _robot);
    return _robot->rotateLeftIfValid();
}

CommandType CommandLeft::getCommandType() const {
    return CommandType::Left;
}
}
