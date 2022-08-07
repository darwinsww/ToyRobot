#ifndef TOYROBOT_COMMANDMOVE_H
#define TOYROBOT_COMMANDMOVE_H

#include "Command.h"

namespace ToyRobot
{
class CommandMove : public Command {
public:
    explicit CommandMove(std::shared_ptr<Robot> &robot);

    bool executeCommand() override;
    CommandType getCommandType() const override;
};
}

#endif //TOYROBOT_COMMANDMOVE_H
