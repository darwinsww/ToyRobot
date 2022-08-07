#ifndef TOYROBOT_COMMANDPLACE_H
#define TOYROBOT_COMMANDPLACE_H

#include "Command.h"

namespace ToyRobot
{
class CommandPlace : public Command {
public:
    explicit CommandPlace(std::shared_ptr<Robot> &robot);

    bool executeCommand() override;
    CommandType getCommandType() const override;

    void setPosition(const Position &newPosition);

private:
    Position _position;
};
}

#endif //TOYROBOT_COMMANDPLACE_H
