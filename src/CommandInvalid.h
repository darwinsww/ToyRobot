#ifndef TOYROBOT_COMMANDINVALID_H
#define TOYROBOT_COMMANDINVALID_H

#include "Command.h"

namespace ToyRobot
{
class CommandInvalid : public Command {
public:
    explicit CommandInvalid(std::shared_ptr<Robot> &robot);

    bool executeCommand() override;
};
}

#endif //TOYROBOT_COMMANDINVALID_H
