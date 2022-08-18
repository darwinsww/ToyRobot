#ifndef TOYROBOT_COMMANDRIGHT_H
#define TOYROBOT_COMMANDRIGHT_H

#include "Command.h"

namespace ToyRobot
{
class CommandRight : public Command {
public:
    explicit CommandRight(std::shared_ptr<Robot> &robot);

    bool executeCommand() override;
};
}

#endif //TOYROBOT_COMMANDRIGHT_H
