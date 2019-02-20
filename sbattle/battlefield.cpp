#include "battlefield.h"

BattleField::BattleField(int top_x, int top_y)
{
    int x = top_x;
    int y = top_y;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            navy[i][j] = Cell(x, y);
            x += CELL_LENX;

        }
        x = top_x;
        y += CELL_LENY;
    }
}
