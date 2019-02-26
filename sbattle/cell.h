#ifndef CELL_H
#define CELL_H

#include <QImage>

enum CellState
{
    ST_EMPTY,
    ST_SHIP,
    ST_DOT,
    ST_HIT
};

class Cell
{
public:
    Cell(int x=0, int y=0);
    // попадание в ячейку - true, мимо - false
    bool hit(int x, int y);
    CellState getState();
    void setState(CellState new_state);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);

private:
    CellState state;
    int top_x, top_y;

};

#endif // CELL_H
