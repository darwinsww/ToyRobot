#ifndef TOYROBOT_COMMANDLEFT_H
#define TOYROBOT_COMMANDLEFT_H

#include "Command.h"

namespace ToyRobot
{
class CommandLeft : public Command {
public:
    explicit CommandLeft(std::shared_ptr<Robot> &robot);

    bool executeCommand() override;
    CommandType getCommandType() const override;
};
}

#endif //TOYROBOT_COMMANDLEFT_H
