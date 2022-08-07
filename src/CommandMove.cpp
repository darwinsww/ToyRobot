#include "CommandMove.h"

#include <cassert>

namespace ToyRobot {
CommandMove::CommandMove(std::shared_ptr<Robot> &robot)
: Command(robot) {

}

bool CommandMove::executeCommand() {
    assert(nullptr != _robot);
    return _robot->moveIfValid();
}

CommandType CommandMove::getCommandType() const {
    return CommandType::Move;
}
}
