#include "cell.h"
#include "images.h"
#include "defines.h"

Cell::Cell(int x, int y) :
    state(ST_EMPTY),
    top_x(x),
    top_y(y)
{
}

bool Cell::hit(int x, int y)
{
    if ( ((x >= this->getX()) && (y >= this->getY())) &&
        ((x<= this->getX() + CELL_LENX) && (y <= this->getY() +  + CELL_LENX)) )
        return true;
    return false;
}

CellState Cell::getState()
{
    return state;
}

void Cell::setState(CellState new_state)
{
    this->state = new_state;
}

int Cell::getX()
{
    return this->top_x;
}

void Cell::setX(int x)
{
    this->top_x = x;
}

int Cell::getY()
{
    return this->top_y;
}

void Cell::setY(int y)
{
    this->top_y = y;
}
