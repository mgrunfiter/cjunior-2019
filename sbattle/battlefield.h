#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "cell.h"
#include "defines.h"

class BattleField
{
public:
    BattleField(int top_x, int top_y);
    Cell navy[10][10];
    int start_x;
    int start_y;
};

#endif // BATTLEFIELD_H
