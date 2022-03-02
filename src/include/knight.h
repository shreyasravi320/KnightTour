#ifndef KNIGHT_H
#define KNIGHT_H

#include "grid.h"

#define UNVISITED -1

extern Grid<int> SOLUTION_6x6;
extern Grid<int> SOLUTION_6x8;
extern Grid<int> SOLUTION_8x8;
extern Grid<int> SOLUTION_8x10;
extern Grid<int> SOLUTION_10x10;

bool solveClosedTourHelper(Grid<int> &grid, int i, int j, int s, int e, int moves);
void solveClosedTour(Grid<int> &grid);

void populateSolutions();

#endif