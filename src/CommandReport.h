#ifndef TOYROBOT_COMMANDREPORT_H
#define TOYROBOT_COMMANDREPORT_H

#include "Command.h"

namespace ToyRobot
{
class CommandReport : public Command {
public:
    explicit CommandReport(std::shared_ptr<Robot> &robot);

    bool executeCommand() override;
    CommandType getCommandType() const override;
};
}

#endif //TOYROBOT_COMMANDREPORT_H
