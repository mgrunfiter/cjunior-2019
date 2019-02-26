#include "battlefield.h"

BattleField::BattleField(int top_x, int top_y):
    start_x(top_x),
    start_y(top_y)
{
    Cell cell(top_x, top_y);
    **navy = {cell};
}
