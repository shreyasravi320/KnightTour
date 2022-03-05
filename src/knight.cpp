#include "include/knight.h"

Grid<int> SOLUTION_6x6;
Grid<int> SOLUTION_6x8;
Grid<int> SOLUTION_8x8;
Grid<int> SOLUTION_8x10;
Grid<int> SOLUTION_10x10;
Grid<int> SOLUTION_10x12;

bool isValid(int n, int m, int i, int j)
{
    return (i >= 0 and i < n and j >= 0 and j < m);
}

void populateSolutions()
{
    SOLUTION_6x6 = 
    {
        { 0, 15, 12, 29,  2, 21},
        {13, 30,  1, 22, 11, 28},
        {16, 35, 14, 27, 20,  3},
        {31,  6, 33, 10, 23, 26},
        {34, 17,  8, 25,  4, 19},
        {7,  32,  5, 18,  9, 24}
    };

    SOLUTION_6x8 = 
    {
        { 0, 39, 18,  9, 28, 35, 20, 11},
        {17,  8, 47, 38, 19, 10, 27, 36},
        {40,  1, 19, 29, 34, 37, 12, 21},
        { 7, 46,  5,  2, 43, 24, 31, 26},
        { 4, 41, 44, 15, 30, 33, 22, 13},
        {45,  6,  3, 42, 23, 14, 25, 32}
    };

    SOLUTION_8x8 = 
    {
        { 0, 59, 14, 23, 46, 35, 12, 25},
        {15, 22, 63, 58, 13, 24, 37, 34},
        {62,  1, 60, 45, 36, 47, 26, 11},
        {21, 16, 55, 48, 57, 50, 33, 38},
        { 2, 61, 20, 51, 44, 39, 10, 27},
        {17, 54, 43, 56, 49, 30,  7, 32},
        {42,  3, 52, 19, 40,  5, 28,  9},
        {53, 18, 41,  4, 29,  8, 31,  6}
    };

    SOLUTION_8x10 = 
    {
        { 0, 45, 36, 65,  2, 47, 34, 67,  4, 7},
        {37, 64,  1, 46, 35, 66,  3,  6, 33, 68},
        {44, 79, 38, 23, 48, 17, 30, 51,  8,  5},
        {63, 22, 43, 20, 29, 14, 49, 18, 69, 32},
        {78, 39, 24, 13, 16, 19, 52, 31, 50,  9},
        {25, 62, 21, 42, 53, 28, 15, 72, 57, 70},
        {40, 77, 60, 27, 12, 75, 58, 55, 10, 73},
        {61, 26, 41, 76, 59, 54, 11, 74, 71, 56}
    };

    SOLUTION_10x10 = 
    {
        { 0, 47, 32, 35, 98, 45, 62, 37, 96, 93},
        {33, 30, 99, 46, 63, 36, 97, 94, 13, 38},
        {48,  1, 34, 31, 44, 75, 66, 61, 92, 95},
        {29, 26, 49, 74, 59, 64, 43, 14, 39, 12},
        { 2, 71, 28, 57, 76, 67, 60, 65, 42, 91},
        {27, 50, 25, 70, 73, 58, 15, 20, 11, 40},
        {24,  3, 72, 77, 56, 21, 68, 41, 90,  9},
        {51, 78, 53, 22, 69, 16, 19, 10, 87, 84},
        { 4, 23, 80, 17,  6, 55, 82, 85,  8, 89},
        {79, 52,  5, 54, 81, 18,  7, 88, 83, 86}
    };

    SOLUTION_10x12 = 
    {
        {  0,   3, 118,  99,  64,   6,  68, 101,  70,   7,  74, 103},
        {117,  98,   1,   4,  67, 100,  41,   6,  27, 102,  71,   8},
        {  2, 119,  96,  63,  40,  65,  24,  69,  38,  73, 104,  75},
        { 97, 116,  47,  66,  61,  42,  39,  26,  59,  28,   9,  72},
        { 92,  95,  62,  43,  46,  25,  60,  23,  32,  37,  76, 105},
        {115,  50,  93,  48,  19,  22,  45,  36,  29,  58,  33,  10},
        { 94,  91, 114,  51,  44,  53,  20,  31,  34,  79, 106,  77},
        {113,  88,  49,  18,  21,  84,  35,  54,  57,  30,  11,  80},
        { 90,  17,  86, 111,  52,  15,  56, 109,  82,  13,  78, 107},
        { 87, 112,  89,  16,  85, 110,  83,  14,  55, 108,  81,  12}
    };
}

void solveClosedTourHelper(Grid<int> &grid, Segment &segment, int i, int j, int n, int m, int move)
{
    /*
     * If the dimension of the sub-board is small enough to be computed in 
     * constant time, fill in that sub-board
     */
    if ((n <= 12 and m <= 10) or (n <= 10 and m <= 12))
    {
        if (n == 6 and m == 6)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_6x6[k - i][l - j];
                }
            }
        }

        else if (n == 6 and m == 8)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_6x8[k - i][l - j];
                }
            }
        }

        else if (n == 8 and m == 6)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_6x8[l - j][k - i];
                }
            }
        }

        else if (n == 8 and m == 8)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_8x8[k - i][l - j];
                }
            }
        }

        else if (n == 8 and m == 10)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_8x10[k - i][l - j];
                }
            }
        }

        else if (n == 10 and m == 8)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_8x10[l - j][k - i];
                }
            }
        }

        else if (n == 10 and m == 10)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_10x10[k - i][l - j];
                }
            }
        }

        else if (n == 10 and m == 12)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_10x12[k - i][l - j];
                }
            }
        }

        else if (n == 12 and m == 10)
        {
            for (int k = i; k < i + n; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    grid[k][l] = move + SOLUTION_10x12[l - j][k - i];
                }
            }
        }

        return;
    }

    /*
     * Otherwise, if n and/or m are larger than 10, divide and recurse
     */
    else
    {
        segment.segments = vector<Segment *>(4);

        /*
         * Four cases for dividing:
         * Case 1: we have a 4k by 4k square
         * Case 2: we have a 4k by (4k + 2) rectangle
         * Case 3: we have a (4k + 2) by (4k + 2) square
         * Case 4: we have a (4k + 2) by (4k + 4) rectangle
         */

        /*
         * Sections go clockwise starting from the top left (1)
         */

        /*
         * Case 1: Divide the 4k by 4k square into 4 2k by 2k squares
         *
         *  |-----------|-----------|
         *  |           |           |
         *  |  2k x 2k  |  2k x 2k  |
         *  |   [0,0]   |  [0,2k]   |
         *  |           |           |
         *  |-----------|-----------|
         *  |           |           |
         *  |  2k x 2k  |  2k x 2k  |
         *  |  [2k,0]   |  [2k,2k]  |
         *  |           |           |
         *  |-----------|-----------|
         */
        if (n == m and n % 4 == 0)
        {
            // first section
            segment.segments[0] = new Segment(n / 2, n / 2, i, j);
            solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2, n / 2, move);

            // second section
            move += (n / 2 * n / 2);
            segment.segments[1] = new Segment(n / 2, n / 2, i, j + n / 2);
            solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2, n / 2, n / 2, move);

            // third section
            move += (n / 2 * n / 2);
            segment.segments[2] = new Segment(n / 2, n / 2, i + n / 2, j + n / 2);
            solveClosedTourHelper(grid, *segment.segments[2], i + n / 2, j + n / 2, n / 2, n / 2, move);

            // fourth section
            move += (n / 2 * n / 2);
            segment.segments[3] = new Segment(n / 2, n / 2, i + n / 2, j);
            solveClosedTourHelper(grid, *segment.segments[3], i + n / 2, j, n / 2, n / 2, move);
        }

        /*
         * Case 2: Divide the 4k by (4k + 2) rectangle into 2 2k by 2k squares
         * and 2 2k by (2k + 2) rectangles
         *
         *  |-----------|-----------|
         *  |           |           |
         *  |  2k x 2k  |  2k x 2k  |
         *  |   [0,0]   |  [0,2k]   |
         *  |           |           |
         *  |-----------|-----------|
         *  |           |           |
         *  |           |           |
         *  |2k x 2k + 2|2k x 2k + 2|
         *  |  [2k,0]   |  [2k,2k]  |
         *  |           |           |
         *  |           |           |
         *  |-----------|-----------|
         */
        if ((n == m - 2 and n % 4 == 0) or (m == n - 2 and m % 4 == 0))
        {
            if (n == m - 2)
            {
                // first section
                segment.segments[0] = new Segment(n / 2, n / 2, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2, n / 2, move);

                // second section
                move += (n / 2 * n / 2);
                segment.segments[1] = new Segment(n / 2, n / 2 + 2, i, j + n / 2);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2, n / 2, n / 2 + 2, move);

                // third section
                move += (n / 2) * (n / 2);
                segment.segments[2] = new Segment(n / 2, n / 2 + 2, i + n / 2, j + n / 2);
                solveClosedTourHelper(grid, *segment.segments[2], i + n / 2, j + n / 2, n / 2, n / 2 + 2, move);

                // fourth section
                move += (n / 2) * (n / 2 + 2);
                segment.segments[3] = new Segment(n / 2, n / 2, i + n / 2, j);
                solveClosedTourHelper(grid, *segment.segments[3], i + n / 2, j, n / 2, n / 2, move);
            }

            else
            {
                // first section
                segment.segments[0] = new Segment(m / 2, m / 2, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, m / 2, m / 2, move);

                // second section
                move += (m / 2 * m / 2);
                segment.segments[1] = new Segment(m / 2, m / 2, i, j + m / 2);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + m / 2, m / 2, m / 2, move);

                // third section
                move += (m / 2) * (m / 2);
                segment.segments[2] = new Segment(m / 2 + 2, m / 2, i + m / 2, j + m / 2);
                solveClosedTourHelper(grid, *segment.segments[2], i + m / 2, j + m / 2, m / 2 + 2, m / 2, move);

                // fourth section
                move += (m / 2) * (m / 2 + 2);
                segment.segments[3] = new Segment(m / 2 + 2, m / 2, i + m / 2, j);
                solveClosedTourHelper(grid, *segment.segments[3], i + m / 2, j, m / 2 + 2, m / 2, move);
            }
        }

        /*
         * Case 3: Divide the (4k + 2) by (4k + 2) square into 
         * 1 2k by 2k square, 1 (2k + 2) by (2k + 2) square, and 
         * 2 2k by (2k + 2) rectangles
         *
         *  |-----------|-------------|
         *  |           |             |
         *  |  2k x 2k  | 2k x 2k + 2 |
         *  |   [0,0]   |  [0,2k]     |
         *  |           |             |
         *  |-----------|-------------|
         *  |           |             |
         *  | 2k x 2k+2 | 2k+2 x 2k+2 |
         *  |  [2k,0]   |  [2k,2k]    |
         *  |           |             |
         *  |           |             |
         *  |-----------|-------------|
         */
        if (n == m and n % 4 == 2)
        {
            // first section
            segment.segments[0] = new Segment(n / 2 - 1, n / 2 - 1, i, j);
            solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2 - 1, n / 2 - 1, move);

            // second section
            move += (n / 2 - 1) * (n / 2 - 1);
            segment.segments[1] = new Segment(n / 2 - 1, n / 2 + 1, i, j + n / 2 - 1);
            solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2 - 1, n / 2 - 1, n / 2 + 1, move);

            // third section
            move += (n / 2 - 1) * (n / 2 + 1);
            segment.segments[2] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j + n / 2 - 1);
            solveClosedTourHelper(grid, *segment.segments[2], i + n / 2 - 1, j + n / 2 - 1, n / 2 + 1, n / 2 + 1, move);

            // fourth section
            move += (n / 2 + 1) * (n / 2 + 1);
            segment.segments[3] = new Segment(n / 2 + 1, n / 2 - 1, i + n / 2 - 1, j);
            solveClosedTourHelper(grid, *segment.segments[3], i + n / 2 - 1, j, n / 2 + 1, n / 2 - 1, move);
        }

        /*
         * Case 4: Divide the (4k + 2) by (4k + 4) rectangle into 
         * 2 (2k + 2) by (2k + 2) squares and 2 2k by (2k + 2) rectangles
         *
         *  |-----------|-------------|
         *  |           |             |
         *  | 2k x 2k+2 | 2k+2 x 2k+2 |
         *  |   [0,0]   |  [0,2k]     |
         *  |           |             |
         *  |-----------|-------------|
         *  | 2k x 2k+2 | 2k+2 x 2k+2 |
         *  | [2k+2,0]  | [2k+2,2k]   |
         *  |           |             |
         *  |           |             |
         *  |-----------|-------------|
         */
        if ((n == m - 2 and n % 4 == 2) or (m == n - 2 and m % 4 == 2))
        {
            if (n == m - 2)
            {
                // first section
                segment.segments[0] = new Segment(n / 2 - 1, n / 2 + 1, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2 - 1, n / 2 + 1, move);

                // second section
                move += (n / 2 - 1) * (n / 2 + 1);
                segment.segments[1] = new Segment(n / 2 - 1, n / 2 + 1, i, j + n / 2 + 1);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2 + 1, n / 2 - 1, n / 2 + 1, move);

                // third section
                move += (n / 2 - 1) * (n / 2 + 1);
                segment.segments[2] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j + n / 2 + 1);
                solveClosedTourHelper(grid, *segment.segments[2], i + n / 2 - 1, j + n / 2 + 1, n / 2 + 1, n / 2 + 1, move);

                // fourth section
                move += (n / 2 + 1) * (n / 2 + 1);
                segment.segments[3] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j);
                solveClosedTourHelper(grid, *segment.segments[3], i + n / 2 - 1, j, n / 2 + 1, n / 2 + 1, move);
            }

            else
            {
                // first section
                segment.segments[0] = new Segment(m / 2 + 1, m / 2 - 1, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, m / 2 + 1, m / 2 - 1, move);

                // second section
                move += (m / 2 + 1) * (m / 2 - 1);
                segment.segments[1] = new Segment(m / 2 + 1, m / 2 + 1, i, j + n / 2 - 1);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + m / 2 - 1, m / 2 + 1, m / 2 + 1, move);

                // third section
                move += (m / 2 + 1) * (m / 2 + 1);
                segment.segments[2] = new Segment(m / 2 + 1, m / 2 + 1, i + m / 2 + 1, j + n / 2 - 1);
                solveClosedTourHelper(grid, *segment.segments[2], i + m / 2 + 1, j + m / 2 - 1, m / 2 + 1, m / 2 + 1, move);

                // fourth section
                move += (m / 2 + 1) * (m / 2 + 1);
                segment.segments[3] = new Segment(m / 2 + 1, m / 2 - 1, i + m / 2 + 1, j);
                solveClosedTourHelper(grid, *segment.segments[3], i + m / 2 + 1, j, m / 2 + 1, m / 2 - 1, move);
            }
        }
    }

    solveClosedTourMerge(grid, segment);
}

void findPairsHelper(Grid<int> &grid, Segment &segment, int section, int i, int j)
{
    int n = segment.segments[section]->n, m = segment.segments[section]->m;
    int k = segment.segments[section]->i, l = segment.segments[section]->j;

    vector<int> delta_i = {1, 2,  2,  1, -1, -2, -2, -1};
    vector<int> delta_j = {2, 1, -1, -2, -2, -1,  1,  2};

    for (int d = 0; d < 8; d++)
    {
        if (isValid(n, m, i + delta_i[d], j + delta_j[d]))
        //  and (
        //     isValid(2, 2, i + delta_i[d] - (n - 4), j + delta_j[d] - (m - 2)) or 
        //     isValid(2, 4, i + delta_i[d] - (n - 2), j + delta_j[d] - (m - 4))
        // )
        {
            if (abs(grid[i + k][j + l] - grid[i + delta_i[d] + k][j + delta_j[d] + l]) == 1)
            {
                segment.pairs[section][grid[i + k][j + l]].insert(grid[i + delta_i[d] + k][j + delta_j[d] + l]);
                // segment.pairs[section][grid[i + delta_i[d] + k][j + delta_j[d] + l]].insert(grid[i + k][j + l]);
            }
        }
    }
}

void findPairs(Grid<int> &grid, Segment &segment, int section)
{
    int n = segment.segments[section]->n, m = segment.segments[section]->m;
    // int k = segment.segments[section]->i, l = segment.segments[section]->j;

    switch (section)
    {
        case 0:
        {
            for (int i = n - 4; i < n - 2; i++)
            {
                for (int j = m - 2; j < m; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            for (int i = n - 2; i < n; i++)
            {
                for (int j = m - 4; j < m; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            break;
        }
        case 1:
        {
            for (int i = n - 4; i < n - 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            for (int i = n - 2; i < n; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            break;
        }
        case 2:
        {
            for (int i = 2; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            break;
        }
        case 3:
        {
            for (int i = 2; i < 4; i++)
            {
                for (int j = m - 2; j < m; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            for (int i = 0; i < 2; i++)
            {
                for (int j = m - 4; j < m; j++)
                {
                    findPairsHelper(grid, segment, section, i, j);
                }
            }

            break;
        }
        default:
        {
            break;
        }
    }
}

void solveClosedTourMerge(Grid<int> &grid, Segment &segment)
{
    /*
     * Search for pairs of indices that we can modify to create a closed path
     * between different segments
     */
    int n = segment.n, m = segment.m;
    int k = segment.i, l = segment.j;
    segment.pairs = PairMap(segment.segments.size());

    for (int i = 0; i < segment.segments.size(); i++)
    {
        findPairs(grid, segment, i);
    }

    vector<int> delta_i = {1, 2,  2,  1, -1, -2, -2, -1};
    vector<int> delta_j = {2, 1, -1, -2, -2, -1,  1,  2};

    // Search for a path from segment 0->1->2->3->0 via pairs found
}

void solveClosedTour(Grid<int> &grid)
{
    Segment segment(grid.getRows(), grid.getCols(), 0, 0);

    solveClosedTourHelper(grid, segment, 0, 0, grid.getRows(), grid.getCols(), 0);
    // grid.print();
}