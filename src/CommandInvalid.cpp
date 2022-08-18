#include "CommandInvalid.h"

namespace ToyRobot
{
CommandInvalid::CommandInvalid(std::shared_ptr<Robot> &robot)
: Command(robot) {

}

bool CommandInvalid::executeCommand() {
    return false;
}
}
