#include "CommandReport.h"

#include <cassert>

namespace ToyRobot
{
CommandReport::CommandReport(std::shared_ptr<Robot> &robot)
: Command(robot) {

}

bool CommandReport::executeCommand() {
    assert(nullptr != _robot);
    _robot->reportPosition();
    return true;
}

CommandType CommandReport::getCommandType() const {
    return CommandType::Report;
}
}
