#include "src/Robot.h"
#include "src/TableTop.h"
#include "src/CommandFactory.h"

#include <cassert>
#include <iostream>
#include <fstream>

using namespace ToyRobot;

void showUsage()
{
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::cout << "usage: "                                                                             << std::endl;
    std::cout << "  ./toyrobot [file_path] - Get commands from the file designated by the [file_path]" << std::endl;
    std::cout << "  ./toyrobot             - Get commands interactively from standard input"           << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
}

void makeCommandAndExecute(
    CommandFactory &cmdFactory,
    const std::string &commandLine,
    const std::string &delimiter
) {
    auto command = cmdFactory.makeCommand(commandLine, delimiter);
    assert(nullptr != command);
    command->executeCommand();
}

int main(int argc, char* argv[]) {
    constexpr int TABLETOP_UNIT_X = 4;
    constexpr int TABLETOP_UNIT_Y = 4;

    const std::string DELIMITER = " ,";

    TableTop tableTop(TABLETOP_UNIT_X, TABLETOP_UNIT_Y);
    auto robot = std::make_shared<Robot>(tableTop);
    CommandFactory cmdFactory(robot);

    showUsage();
    try {
        if(1 == argc) {
            std::cout << "Reading Command(s) from command line. Please input (Press enter to exit)" << std::endl;

            std::string commandLine;
            while (true) {
                std::getline(std::cin, commandLine);
                if(commandLine.empty()) {
                    break;
                }
                makeCommandAndExecute(cmdFactory, commandLine, DELIMITER);
            }
        } else if(2 == argc){
            const std::string fileFullPath = argv[1];
            std::cout << "Reading Command(s) from the file: " << fileFullPath << std::endl;

            std::ifstream commandFile;
            commandFile.open(fileFullPath);
            if(!commandFile.is_open()) {
                std::cout << "Fail to open file: " << fileFullPath << std::endl;
                return EXIT_FAILURE;
            }

            std::string commandLine;
            while(commandFile.good()) {
                std::getline(commandFile, commandLine);
                if(commandLine.empty()) {
                    continue;
                }
                makeCommandAndExecute(cmdFactory, commandLine, DELIMITER);
            }
        } else {
            std::cout << "Invalid command, please refer to the usage shown above." << std::endl;
            return EXIT_FAILURE;
        }
    }
    catch (std::exception &e) {
        std::cout << "Unknown Exception Raised During Execution: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
