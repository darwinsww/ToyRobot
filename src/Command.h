#ifndef TOYROBOT_COMMAND_H
#define TOYROBOT_COMMAND_H

#include "Robot.h"

#include <string>
#include <memory>

namespace ToyRobot
{
enum class CommandType {
    Invalid = 0,
    Place,
    Move,
    Left,
    Right,
    Report = 5,
};

class Command {
public:
    explicit Command(std::shared_ptr<Robot> &robot);

    virtual bool executeCommand() = 0;
    virtual CommandType getCommandType() const = 0;
    bool isCommandValid() const;

    static CommandType matchCommandType(const std::string &commandText);

protected:
    std::shared_ptr<Robot> _robot;

private:
    static const std::map<std::string, CommandType> _commandsTextToTypeMap;
};
}

#endif //TOYROBOT_COMMAND_H
