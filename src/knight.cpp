#include "include/knight.h"

/*
 * Custom operators in C++ taken from this StackOverflow link:
 * https://stackoverflow.com/questions/1515399/can-you-make-custom-operators-in-c
 * 
 * Main purpose is to create a mod operation that always returns a positive number
 */

#define operator(ReturnType, OperatorName, FirstOperandType, SecondOperandType) OperatorName ## _ {} OperatorName; template <typename T> struct OperatorName ## Proxy{public:OperatorName ## Proxy(const T& t) : t_(t){}const T& t_;static ReturnType _ ## OperatorName ## _(const FirstOperandType a, const SecondOperandType b);};template <typename T> OperatorName ## Proxy<T> operator<(const T& lhs, const OperatorName ## _& rhs){return OperatorName ## Proxy<T>(lhs);}ReturnType operator>(const OperatorName ## Proxy<FirstOperandType>& lhs, const SecondOperandType& rhs){return OperatorName ## Proxy<FirstOperandType>::_ ## OperatorName ## _(lhs.t_, rhs);}template <typename T> inline ReturnType OperatorName ## Proxy<T>::_ ## OperatorName ## _(const FirstOperandType a, const SecondOperandType b)

const struct operator(int, mod, int, int)
{
    return (a % b + b) % b;
};

#define mod <mod>

Grid<int> SOLUTION_6x6;
Grid<int> SOLUTION_6x8;
Grid<int> SOLUTION_8x8;
Grid<int> SOLUTION_8x10;
Grid<int> SOLUTION_10x10;
Grid<int> SOLUTION_10x12;

vector<int> delta_i = {1, 2,  2,  1, -1, -2, -2, -1};
vector<int> delta_j = {2, 1, -1, -2, -2, -1,  1,  2};

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
        {40,  1, 16, 29, 34, 37, 12, 21},
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
        {  0,   3, 118,  99,  64,   5,  68, 101,  70,   7,  74, 103},
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
                    grid(move + SOLUTION_6x6[k - i][l - j]) = {k, l};
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
                    grid(move + SOLUTION_6x8[k - i][l - j]) = {k, l};
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
                    grid(move + SOLUTION_6x8[l - j][k - i]) = {k, l};
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
                    grid(move + SOLUTION_8x8[k - i][l - j]) = {k, l};
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
                    grid(move + SOLUTION_8x10[k - i][l - j]) = {k, l};
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
                    grid(move + SOLUTION_8x10[l - j][k - i]) = {k, l};
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
                    grid(move + SOLUTION_10x10[k - i][l - j]) = {k, l};
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
                    grid(move + SOLUTION_10x12[k - i][l - j]) = {k, l};
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
                    grid(move + SOLUTION_10x12[l - j][k - i]) = {k, l};
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
        if (n == m and n mod 4 == 0)
        {
            // first segment
            segment.segments[0] = new Segment(n / 2, n / 2, i, j);
            solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2, n / 2, move);

            // second segment
            move += (n / 2 * n / 2);
            segment.segments[1] = new Segment(n / 2, n / 2, i, j + n / 2);
            solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2, n / 2, n / 2, move);

            // third segment
            move += (n / 2 * n / 2);
            segment.segments[2] = new Segment(n / 2, n / 2, i + n / 2, j + n / 2);
            solveClosedTourHelper(grid, *segment.segments[2], i + n / 2, j + n / 2, n / 2, n / 2, move);

            // fourth segment
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
        if ((n == m - 2 and n mod 4 == 0) or (m == n - 2 and m mod 4 == 0))
        {
            if (n == m - 2)
            {
                // first segment
                segment.segments[0] = new Segment(n / 2, n / 2, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2, n / 2, move);

                // second segment
                move += (n / 2 * n / 2);
                segment.segments[1] = new Segment(n / 2, n / 2 + 2, i, j + n / 2);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2, n / 2, n / 2 + 2, move);

                // third segment
                move += (n / 2) * (n / 2);
                segment.segments[2] = new Segment(n / 2, n / 2 + 2, i + n / 2, j + n / 2);
                solveClosedTourHelper(grid, *segment.segments[2], i + n / 2, j + n / 2, n / 2, n / 2 + 2, move);

                // fourth segment
                move += (n / 2) * (n / 2 + 2);
                segment.segments[3] = new Segment(n / 2, n / 2, i + n / 2, j);
                solveClosedTourHelper(grid, *segment.segments[3], i + n / 2, j, n / 2, n / 2, move);
            }

            else
            {
                // first segment
                segment.segments[0] = new Segment(m / 2, m / 2, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, m / 2, m / 2, move);

                // second segment
                move += (m / 2 * m / 2);
                segment.segments[1] = new Segment(m / 2, m / 2, i, j + m / 2);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + m / 2, m / 2, m / 2, move);

                // third segment
                move += (m / 2) * (m / 2);
                segment.segments[2] = new Segment(m / 2 + 2, m / 2, i + m / 2, j + m / 2);
                solveClosedTourHelper(grid, *segment.segments[2], i + m / 2, j + m / 2, m / 2 + 2, m / 2, move);

                // fourth segment
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
        if (n == m and n mod 4 == 2)
        {
            // first segment
            segment.segments[0] = new Segment(n / 2 - 1, n / 2 - 1, i, j);
            solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2 - 1, n / 2 - 1, move);

            // second segment
            move += (n / 2 - 1) * (n / 2 - 1);
            segment.segments[1] = new Segment(n / 2 - 1, n / 2 + 1, i, j + n / 2 - 1);
            solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2 - 1, n / 2 - 1, n / 2 + 1, move);

            // third segment
            move += (n / 2 - 1) * (n / 2 + 1);
            segment.segments[2] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j + n / 2 - 1);
            solveClosedTourHelper(grid, *segment.segments[2], i + n / 2 - 1, j + n / 2 - 1, n / 2 + 1, n / 2 + 1, move);

            // fourth segment
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
        if ((n == m - 2 and n mod 4 == 2) or (m == n - 2 and m mod 4 == 2))
        {
            if (n == m - 2)
            {
                // first segment
                segment.segments[0] = new Segment(n / 2 - 1, n / 2 + 1, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, n / 2 - 1, n / 2 + 1, move);

                // second segment
                move += (n / 2 - 1) * (n / 2 + 1);
                segment.segments[1] = new Segment(n / 2 - 1, n / 2 + 1, i, j + n / 2 + 1);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + n / 2 + 1, n / 2 - 1, n / 2 + 1, move);

                // third segment
                move += (n / 2 - 1) * (n / 2 + 1);
                segment.segments[2] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j + n / 2 + 1);
                solveClosedTourHelper(grid, *segment.segments[2], i + n / 2 - 1, j + n / 2 + 1, n / 2 + 1, n / 2 + 1, move);

                // fourth segment
                move += (n / 2 + 1) * (n / 2 + 1);
                segment.segments[3] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j);
                solveClosedTourHelper(grid, *segment.segments[3], i + n / 2 - 1, j, n / 2 + 1, n / 2 + 1, move);
            }

            else
            {
                // first segment
                segment.segments[0] = new Segment(m / 2 + 1, m / 2 - 1, i, j);
                solveClosedTourHelper(grid, *segment.segments[0], i, j, m / 2 + 1, m / 2 - 1, move);

                // second segment
                move += (m / 2 + 1) * (m / 2 - 1);
                segment.segments[1] = new Segment(m / 2 + 1, m / 2 + 1, i, j + n / 2 - 1);
                solveClosedTourHelper(grid, *segment.segments[1], i, j + m / 2 - 1, m / 2 + 1, m / 2 + 1, move);

                // third segment
                move += (m / 2 + 1) * (m / 2 + 1);
                segment.segments[2] = new Segment(m / 2 + 1, m / 2 + 1, i + m / 2 + 1, j + n / 2 - 1);
                solveClosedTourHelper(grid, *segment.segments[2], i + m / 2 + 1, j + m / 2 - 1, m / 2 + 1, m / 2 + 1, move);

                // fourth segment
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

    for (int d = 0; d < 8; d++)
    {
        bool ok = isValid(n, m, i + delta_i[d], j + delta_j[d]);
        switch (section)
        {
            case 0:
            {
                ok = ok and (isValid(2, 2, i + delta_i[d] - (n - 4), j + delta_j[d] - (m - 2)) or
                             isValid(2, 4, i + delta_i[d] - (n - 2), j + delta_j[d] - (m - 4)));
                break;
            }
            case 1:
            {
                ok = ok and (isValid(2, 2, i + delta_i[d] - (n - 4), j + delta_j[d]) or
                             isValid(2, 4, i + delta_i[d] - (n - 2), j + delta_j[d]));
                break;
            }
            case 2:
            {
                ok = ok and (isValid(2, 2, i + delta_i[d], j + delta_j[d]) or
                             isValid(2, 4, i + delta_i[d], j + delta_j[d]));
                break;
            }
            case 3:
            {
                ok = ok and (isValid(2, 2, i + delta_i[d], j + delta_j[d] - (m - 2)) or
                             isValid(2, 4, i + delta_i[d], j + delta_j[d] - (m - 4)));
                break;
            }
            default:
            {
                break;
            }
        }
        if (ok)
        {
            if (abs(grid[i + k][j + l] - grid[i + delta_i[d] + k][j + delta_j[d] + l]) == 1)
            {
                segment.pairs[section][grid[i + k][j + l]].insert(grid[i + delta_i[d] + k][j + delta_j[d] + l]);
            }
        }
    }
}

void findPairs(Grid<int> &grid, Segment &segment, int section)
{
    int n = segment.segments[section]->n, m = segment.segments[section]->m;

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

vector<int> findPath(Grid<int> &grid, Segment &segment)
{
    /*
     * Iterate over all starting locations for the search. We always start the
     * search from the entry point, and push the exit point into the stack
     * to then continue the search at the next segment
     */
    unordered_map<int, bool> visited;
    for (auto &[x, y] : segment.pairs[0])
    {
        int entrance = x;
        int currSegment = 1;

        stack<vector<int>> s;
        vector<int> path;
        path.push_back(entrance);

        /*
         * Maximum of 2 values in the set of consecutive vertices confined to 
         * the region that allows for a knight's tour to be completed and a
         * transition to the next segment
         */

        for (auto it = segment.pairs[0][entrance].begin(); it != segment.pairs[0][entrance].end(); it++)
        {
            path.push_back(*it);
            s.push(path);

            /*
             * Slightly modified BFS algorithm: in this version, we force 
             * moving to the next segment since the path has to be
             * of length 4, with two vertices in each segment
             */
            while (not s.empty())
            {
                /*
                 * Even if we push back multiple neighbors, make sure we only
                 * increment the segment mod 4 once for all neighbors of a
                 * segment
                 */
                bool addOne = true;

                path = s.top();
                s.pop();
                int v = path[path.size() - 1];

                bool ok = false;

                switch (currSegment)
                {
                    // Exit point from segment 1 to 2 has already been pushed
                    case 1:
                    {
                        /*
                         * From segment 1 to segment 2, the deltas we have to
                         * check are (1, 2), (2, 1), (-1, 2), (-2, 1)
                         * 
                         * This corresponds to deltas 0, 1, 6, and 7 in the
                         * delta_i and delta_j tables
                         */
                        
                        vector<int> idxs = {0, 1, 6, 7};
                        vector<int> currLoc = grid(v);

                        for (int i = 0; i < 4; i++)
                        {
                            vector<int> nextLoc = {currLoc[0] + delta_i[idxs[i]], currLoc[1] + delta_j[idxs[i]]};

                            if (isValid(grid.getRows(), grid.getCols(), nextLoc[0], nextLoc[1]))
                            {
                                if (segment.pairs[currSegment].count(grid[nextLoc[0]][nextLoc[1]]))
                                {
                                    ok = true;

                                    for (auto itt = segment.pairs[currSegment][grid[nextLoc[0]][nextLoc[1]]].begin();
                                              itt != segment.pairs[currSegment][grid[nextLoc[0]][nextLoc[1]]].end();
                                              itt++)
                                    {
                                        vector<int> newPath(path);
                                        newPath.push_back(grid[nextLoc[0]][nextLoc[1]]);
                                        newPath.push_back(*itt);

                                        s.push(newPath);
                                    }

                                    if (addOne)
                                    {
                                        currSegment++;
                                        currSegment = currSegment mod 4;

                                        addOne = false;
                                    }
                                }
                            }
                        }

                        break;
                    }

                    // Exit point from segment 2 to 3 has already been pushed
                    case 2:
                    {
                        /*
                         * From segment 2 to segment 3, the deltas we have to
                         * check are (1, 2), (2, 1), (2, -1), (1, -2)
                         * 
                         * This corresponds to deltas 0, 1, 2, and 3 in the
                         * delta_i and delta_j tables
                         */
                        
                        vector<int> currLoc = grid(v);

                        for (int i = 0; i < 4; i++)
                        {
                            vector<int> nextLoc = {currLoc[0] + delta_i[i], currLoc[1] + delta_j[i]};

                            if (isValid(grid.getRows(), grid.getCols(), nextLoc[0], nextLoc[1]))
                            {
                                if (segment.pairs[currSegment].count(grid[nextLoc[0]][nextLoc[1]]))
                                {
                                    ok = true;
                                    
                                    for (auto itt = segment.pairs[currSegment][grid[nextLoc[0]][nextLoc[1]]].begin();
                                              itt != segment.pairs[currSegment][grid[nextLoc[0]][nextLoc[1]]].end();
                                              itt++)
                                    {
                                        vector<int> newPath(path);
                                        newPath.push_back(grid[nextLoc[0]][nextLoc[1]]);
                                        newPath.push_back(*itt);

                                        s.push(newPath);
                                    }

                                    if (addOne)
                                    {
                                        currSegment++;
                                        currSegment = currSegment mod 4;

                                        addOne = false;
                                    }
                                }
                            }
                        }

                        break;
                    }

                    // Exit point from segment 3 to 4 has already been pushed
                    case 3:
                    {
                        /*
                         * From segment 3 to segment 4, the deltas we have to
                         * check are (2, -1), (1, -2), (-1, -2), (-2, -1)
                         * 
                         * This corresponds to deltas 2, 3, 4, and 5 in the
                         * delta_i and delta_j tables
                         */
                        
                        vector<int> currLoc = grid(v);

                        for (int i = 2; i < 6; i++)
                        {
                            vector<int> nextLoc = {currLoc[0] + delta_i[i], currLoc[1] + delta_j[i]};

                            if (isValid(grid.getRows(), grid.getCols(), nextLoc[0], nextLoc[1]))
                            {
                                if (segment.pairs[currSegment].count(grid[nextLoc[0]][nextLoc[1]]))
                                {
                                    ok = true;
                                    
                                    for (auto itt = segment.pairs[currSegment][grid[nextLoc[0]][nextLoc[1]]].begin();
                                              itt != segment.pairs[currSegment][grid[nextLoc[0]][nextLoc[1]]].end();
                                              itt++)
                                    {
                                        vector<int> newPath(path);
                                        newPath.push_back(grid[nextLoc[0]][nextLoc[1]]);
                                        newPath.push_back(*itt);

                                        s.push(newPath);
                                    }

                                    if (addOne)
                                    {
                                        currSegment++;
                                        currSegment = currSegment mod 4;

                                        addOne = false;
                                    }
                                }
                            }
                        }

                        break;
                    }

                    // Exit point from segment 4 to 1 has already been pushed
                    case 0:
                    {
                        /*
                         * From segment 4 to segment 1, the deltas we have to
                         * check are (-1, -2), (-2, -1), (-2, 1), (-1, 2)
                         * 
                         * This corresponds to deltas 4, 5, 6, and 7 in the
                         * delta_i and delta_j tables
                         */
                        
                        vector<int> currLoc = grid(v);

                        for (int i = 4; i < 8; i++)
                        {
                            vector<int> nextLoc = {currLoc[0] + delta_i[i], currLoc[1] + delta_j[i]};

                            if (isValid(grid.getRows(), grid.getCols(), nextLoc[0], nextLoc[1]))
                            {
                                if (grid[nextLoc[0]][nextLoc[1]] == entrance)
                                {
                                    ok = true;
                                    path.push_back(entrance);
                                    return path;
                                }
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
        }
    }

    return {};
}

void traverseSegments(Grid<int> &grid, Segment &segment, const vector<int> &path)
{
    Grid<int> copy = grid;

    for (int currSegment = 0; currSegment < 4; currSegment++)
    {
        int n = segment.segments[currSegment]->n;
        int m = segment.segments[currSegment]->m;
        int i = segment.segments[currSegment]->i;
        int j = segment.segments[currSegment]->j;

        int a = 1e9;
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < m; l++)
            {
                a = min(a, grid[i + k][j + l]);
            }
        }
        int start = path[currSegment * 2] - a;
        int count = 0;
        int k = start;

        bool rev = segment.segments[currSegment]->reversed;

        if (not rev)
        {
            do
            {
                int num = (a + count++);

                vector<int> loc = grid(k + a);
                copy[loc[0]][loc[1]] = num;
                copy(num) = loc;
                k = ((k + 1) % (n * m));

            } while (k != start);
        }
        else
        {
            do
            {
                int num = (a + count++);

                vector<int> loc = grid(k + a);
                copy[loc[0]][loc[1]] = num;
                copy(num) = loc;
                k = ((k - 1) mod (n * m));

            } while (k != ((start) mod (n * m)));
        }
    }

    grid = copy;
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

    // Find a path that connects 4 segments together
    vector<int> path = findPath(grid, segment);

    // Indicate which segments need to be completed in reverse order
    for (int i = 0; i < path.size() - 2; i += 2)
    {
        if (path[i] < path[i + 1])
        {
            segment.segments[i / 2]->reversed = true;
        }
    }

    traverseSegments(grid, segment, path);
}

void solveClosedTour(Grid<int> &grid)
{
    Segment segment(grid.getRows(), grid.getCols(), 0, 0);

    solveClosedTourHelper(grid, segment, 0, 0, grid.getRows(), grid.getCols(), 0);
}