#include "Command.h"

namespace ToyRobot
{
std::map<std::string, CommandType> createCommandsTextToTypeMap() {
    std::map<std::string, CommandType> commandsTextToTypeMap;
    commandsTextToTypeMap["INVALID"] = CommandType::Invalid;
    commandsTextToTypeMap["PLACE"] = CommandType::Place;
    commandsTextToTypeMap["MOVE"] = CommandType::Move;
    commandsTextToTypeMap["LEFT"] = CommandType::Left;
    commandsTextToTypeMap["RIGHT"] = CommandType::Right;
    commandsTextToTypeMap["REPORT"] = CommandType::Report;

    return commandsTextToTypeMap;
}

const std::map<std::string, CommandType> Command::_commandsTextToTypeMap = createCommandsTextToTypeMap();

Command::Command(std::shared_ptr<Robot> &robot)
: _robot(robot) {

}

CommandType Command::matchCommandType(const std::string &commandText) {
    CommandType commandType = CommandType::Invalid;

    const auto iterator = _commandsTextToTypeMap.find(commandText);
    if (_commandsTextToTypeMap.end() != iterator) {
        commandType = iterator->second;
    }

    return commandType;
}
}
