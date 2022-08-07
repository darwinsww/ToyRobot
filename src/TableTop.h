#ifndef TOYROBOT_TABLETOP_H
#define TOYROBOT_TABLETOP_H

namespace ToyRobot
{
class TableTop {
public:
    TableTop(int dimensionX, int dimensionY);

    bool isOnTable(int x, int y) const;

private:
    int _dimensionX;
    int _dimensionY;
};
}

#endif //TOYROBOT_TABLETOP_H
