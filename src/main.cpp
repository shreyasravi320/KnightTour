#include "Grid.h"

int main(int argc, char **argv)
{
    Grid<int> grid(3, 3, 5);
    grid.print();

    cout << grid[0][0] << "\n";

    return 0;
}