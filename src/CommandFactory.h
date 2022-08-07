#ifndef TOYROBOT_COMMANDFACTORY_H
#define TOYROBOT_COMMANDFACTORY_H

#include "Command.h"
#include "CommandPlace.h"
#include "CommandMove.h"
#include "CommandLeft.h"
#include "CommandRight.h"
#include "CommandReport.h"
#include "CommandInvalid.h"

#include <string>
#include <vector>
#include <memory>

namespace ToyRobot
{
class CommandFactory {
public:
    explicit CommandFactory(std::shared_ptr<Robot> &robot);

    std::shared_ptr<Command> makeCommand(
        const std::string &command,
        const std::string &delimiter
    );

private:
    void getAllTrimmedCommandElementsUpperCase(const std::string &command, const std::string &delimiter);
    bool isElementsCountValid() const;
    Position getNewPosition() const;

private:
    std::shared_ptr<Robot> _robot;
    std::vector<std::string> _commandElements;

    std::shared_ptr<CommandPlace> _placeCommand;
    std::shared_ptr<CommandMove> _moveCommand;
    std::shared_ptr<CommandLeft> _leftCommand;
    std::shared_ptr<CommandRight> _rightCommand;
    std::shared_ptr<CommandReport> _reportCommand;
    std::shared_ptr<CommandInvalid> _invalidCommand;
};
}

#endif //TOYROBOT_COMMANDFACTORY_H
