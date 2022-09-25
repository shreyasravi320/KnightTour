#include "include/viewer.h"

int main(int argc, char **argv)
{
    populateSolutions();

    int n;

    if (argc < 2)
    {
        cout << "Enter the side length of the board: ";
        cin >> n;
    }
    else
    {
        n = stoi(argv[1]);
    }

    if (n % 2)
    {
        cout << "A closed knight's tour cannot be performed on a square board of odd area.\n";
        return 0;
    }

    if (n < 6)
    {
        cout << "A closed knight's tour cannot be performed on a square board smaller than 6x6.\n";
        return 0;
    }

    Viewer viewer = Viewer(n);

    while (viewer.getWindowIsOpen())
    {
        viewer.update();
        viewer.render();
    }

    return 0;
}
