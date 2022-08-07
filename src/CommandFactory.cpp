#include "CommandFactory.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

namespace ToyRobot
{
static const int maxCountOfCommandElements = 4;

CommandFactory::CommandFactory(std::shared_ptr<Robot> &robot)
: _robot (robot) {
    _commandElements.reserve(maxCountOfCommandElements);

    _placeCommand = std::make_shared<CommandPlace>(_robot);
    _moveCommand = std::make_shared<CommandMove>(_robot);
    _leftCommand = std::make_shared<CommandLeft>(_robot);
    _rightCommand = std::make_shared<CommandRight>(_robot);
    _reportCommand = std::make_shared<CommandReport>(_robot);
    _invalidCommand = std::make_shared<CommandInvalid>(_robot);
}

std::shared_ptr<Command> CommandFactory::makeCommand(
    const std::string &command,
    const std::string &delimiter
) {
    getAllTrimmedCommandElementsUpperCase(command, delimiter);

    if (!isElementsCountValid()) {
        return _invalidCommand;
    }

    CommandType commandType = Command::matchCommandType(_commandElements[0]);
    switch (commandType) {
        case CommandType::Place: {
            Position newPosition = getNewPosition();
            if(!newPosition.isValid()) {
                return _invalidCommand;
            }

            _placeCommand->setPosition(newPosition);
            return _placeCommand;
        }
        case CommandType::Move:
            return _moveCommand;
        case CommandType::Left:
            return _leftCommand;
        case CommandType::Right:
            return _rightCommand;
        case CommandType::Report:
            return _reportCommand;
        default:
            return _invalidCommand;
    }
}

void CommandFactory::getAllTrimmedCommandElementsUpperCase(const std::string &command, const std::string &delimiter) {
    std::string tmpCommand = boost::to_upper_copy(command);
    boost::algorithm::trim(tmpCommand);
    boost::split(_commandElements, tmpCommand, boost::is_any_of(delimiter));
}

bool CommandFactory::isElementsCountValid() const {
    if (1 == _commandElements.size() || maxCountOfCommandElements == _commandElements.size()) {
        return true;
    }

    return false;
}

Position CommandFactory::getNewPosition() const {
    try {
        return {
            boost::lexical_cast<int>(_commandElements[1]),
            boost::lexical_cast<int>(_commandElements[2]),
            _commandElements[3]
        };
    }
    catch (const boost::bad_lexical_cast &e) {
        return {};
    }
}
}
