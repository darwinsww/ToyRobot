#ifndef TOYROBOT_TEST_TOYROBOT_H
#define TOYROBOT_TEST_TOYROBOT_H

#include "TableTop.h"
#include "Robot.h"
#include "CommandFactory.h"

#include "gtest/gtest.h"

using namespace ToyRobot;

namespace UnitTestToyRobot
{
class test_ToyRobot : public testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();

        _robot = std::make_shared<Robot>(TableTop {DIMENSIONX, DIMENSIONY});
        _cmdFactory = std::make_shared<CommandFactory>(_robot);
    }

    void TearDown() override {
        Test::TearDown();

        _robot.reset();
        _cmdFactory.reset();
    }

    static std::string toString(int x, int y, const std::string &direction) {
        return std::to_string(x) + "," + std::to_string(y) + "," + direction;
    }

protected:
    const std::string PLACE = "PLACE";
    const std::string MOVE = "MOVE";
    const std::string LEFT = "LEFT";
    const std::string RIGHT = "RIGHT";
    const std::string REPORT = "REPORT";

    const std::string NORTH = "NORTH";
    const std::string EAST = "EAST";
    const std::string SOUTH = "SOUTH";
    const std::string WEST = "WEST";
    const std::string UNDEFINED = "UNDEFINED";

    const std::string DELIMITER = " ,";

    const int DIMENSIONX = 4;
    const int DIMENSIONY = 4;

    std::shared_ptr<Robot> _robot;
    std::shared_ptr<CommandFactory> _cmdFactory;
};
}

#endif //TOYROBOT_TEST_TOYROBOT_H
