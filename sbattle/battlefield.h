#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "cell.h"
#include "defines.h"

class BattleField
{
public:
    BattleField(int top_x, int top_y);
    Cell navy;
};

#endif // BATTLEFIELD_H
