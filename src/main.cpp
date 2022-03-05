#include "viewer.h"

int main(int argc, char **argv)
{
    populateSolutions();

    Grid<int> grid(22, 22, UNVISITED);
    solveClosedTour(grid);
    // Viewer viewer = Viewer(30);

    // while (viewer.getWindowIsOpen())
    // {
    //     viewer.update();
    //     viewer.render();
    // }

    return 0;
}