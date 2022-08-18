#include "CommandRight.h"

#include <cassert>

namespace ToyRobot
{
CommandRight::CommandRight(std::shared_ptr<Robot> &robot)
: Command(robot) {

}

bool CommandRight::executeCommand() {
    assert(nullptr != _robot);
    return _robot->rotateRightIfValid();
}
}
