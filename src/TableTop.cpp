#include "TableTop.h"

namespace ToyRobot
{
TableTop::TableTop(int dimensionX, int dimensionY)
: _dimensionX(dimensionX)
, _dimensionY(dimensionY) {

}

bool TableTop::isOnTable(int x, int y) const {
    return (x >= 0) && (x <= _dimensionX)
        && (y >= 0) && (y <= _dimensionY);
}
}
