#include "include/knight.h"
#include <fstream>
#include <cassert>
#include <algorithm>

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
        { 7, 32,  5, 18,  9, 24}
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

void solveClosedTourHelper(Grid<int> &grid, Segment *segment, int i, int j, int n, int m, int move)
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
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
                    grid(grid[k][l]) = {k, l};
                }
            }
        }

        // return;
    }

    /*
     * Otherwise, if n and/or m are larger than 10, divide and recurse
     */
    else
    {
        segment->segments = vector<Segment *>(4);

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
            segment->segments[0] = new Segment(n / 2, n / 2, i, j);
            solveClosedTourHelper(grid, segment->segments[0], i, j, n / 2, n / 2, move);

            // second segment
            move += (n / 2 * n / 2);
            segment->segments[1] = new Segment(n / 2, n / 2, i, j + n / 2);
            solveClosedTourHelper(grid, segment->segments[1], i, j + n / 2, n / 2, n / 2, move);

            // third segment
            move += (n / 2 * n / 2);
            segment->segments[2] = new Segment(n / 2, n / 2, i + n / 2, j + n / 2);
            solveClosedTourHelper(grid, segment->segments[2], i + n / 2, j + n / 2, n / 2, n / 2, move);

            // fourth segment
            move += (n / 2 * n / 2);
            segment->segments[3] = new Segment(n / 2, n / 2, i + n / 2, j);
            solveClosedTourHelper(grid, segment->segments[3], i + n / 2, j, n / 2, n / 2, move);
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
                segment->segments[0] = new Segment(n / 2, n / 2, i, j);
                solveClosedTourHelper(grid, segment->segments[0], i, j, n / 2, n / 2, move);

                // second segment
                move += (n / 2 * n / 2);
                segment->segments[1] = new Segment(n / 2, n / 2 + 2, i, j + n / 2);
                solveClosedTourHelper(grid, segment->segments[1], i, j + n / 2, n / 2, n / 2 + 2, move);

                // third segment
                move += (n / 2) * (n / 2 + 2);
                segment->segments[2] = new Segment(n / 2, n / 2 + 2, i + n / 2, j + n / 2);
                solveClosedTourHelper(grid, segment->segments[2], i + n / 2, j + n / 2, n / 2, n / 2 + 2, move);

                // fourth segment
                move += (n / 2) * (n / 2 + 2);
                segment->segments[3] = new Segment(n / 2, n / 2, i + n / 2, j);
                solveClosedTourHelper(grid, segment->segments[3], i + n / 2, j, n / 2, n / 2, move);
            }

            else
            {
                // first segment
                segment->segments[0] = new Segment(m / 2, m / 2, i, j);
                solveClosedTourHelper(grid, segment->segments[0], i, j, m / 2, m / 2, move);

                // second segment
                move += (m / 2 * m / 2);
                segment->segments[1] = new Segment(m / 2, m / 2, i, j + m / 2);
                solveClosedTourHelper(grid, segment->segments[1], i, j + m / 2, m / 2, m / 2, move);

                // third segment
                move += (m / 2) * (m / 2);
                segment->segments[2] = new Segment(m / 2 + 2, m / 2, i + m / 2, j + m / 2);
                solveClosedTourHelper(grid, segment->segments[2], i + m / 2, j + m / 2, m / 2 + 2, m / 2, move);

                // fourth segment
                move += (m / 2) * (m / 2 + 2);
                segment->segments[3] = new Segment(m / 2 + 2, m / 2, i + m / 2, j);
                solveClosedTourHelper(grid, segment->segments[3], i + m / 2, j, m / 2 + 2, m / 2, move);
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
            segment->segments[0] = new Segment(n / 2 - 1, n / 2 - 1, i, j);
            solveClosedTourHelper(grid, segment->segments[0], i, j, n / 2 - 1, n / 2 - 1, move);

            // second segment
            move += (n / 2 - 1) * (n / 2 - 1);
            segment->segments[1] = new Segment(n / 2 - 1, n / 2 + 1, i, j + n / 2 - 1);
            solveClosedTourHelper(grid, segment->segments[1], i, j + n / 2 - 1, n / 2 - 1, n / 2 + 1, move);

            // third segment
            move += (n / 2 - 1) * (n / 2 + 1);
            segment->segments[2] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j + n / 2 - 1);
            solveClosedTourHelper(grid, segment->segments[2], i + n / 2 - 1, j + n / 2 - 1, n / 2 + 1, n / 2 + 1, move);

            // fourth segment
            move += (n / 2 + 1) * (n / 2 + 1);
            segment->segments[3] = new Segment(n / 2 + 1, n / 2 - 1, i + n / 2 - 1, j);
            solveClosedTourHelper(grid, segment->segments[3], i + n / 2 - 1, j, n / 2 + 1, n / 2 - 1, move);
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
                segment->segments[0] = new Segment(n / 2 - 1, n / 2 + 1, i, j);
                solveClosedTourHelper(grid, segment->segments[0], i, j, n / 2 - 1, n / 2 + 1, move);

                // second segment
                move += (n / 2 - 1) * (n / 2 + 1);
                segment->segments[1] = new Segment(n / 2 - 1, n / 2 + 1, i, j + n / 2 + 1);
                solveClosedTourHelper(grid, segment->segments[1], i, j + n / 2 + 1, n / 2 - 1, n / 2 + 1, move);

                // third segment
                move += (n / 2 + 1) * (n / 2 - 1);
                segment->segments[2] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j + n / 2 + 1);
                solveClosedTourHelper(grid, segment->segments[2], i + n / 2 - 1, j + n / 2 + 1, n / 2 + 1, n / 2 + 1, move);

                // fourth segment
                move += (n / 2 + 1) * (n / 2 + 1);
                segment->segments[3] = new Segment(n / 2 + 1, n / 2 + 1, i + n / 2 - 1, j);
                solveClosedTourHelper(grid, segment->segments[3], i + n / 2 - 1, j, n / 2 + 1, n / 2 + 1, move);
            }

            else
            {
                // first segment
                segment->segments[0] = new Segment(m / 2 + 1, m / 2 - 1, i, j);
                solveClosedTourHelper(grid, segment->segments[0], i, j, m / 2 + 1, m / 2 - 1, move);

                // second segment
                move += (m / 2 + 1) * (m / 2 - 1);
                segment->segments[1] = new Segment(m / 2 + 1, m / 2 + 1, i, j + m / 2 - 1);
                solveClosedTourHelper(grid, segment->segments[1], i, j + m / 2 - 1, m / 2 + 1, m / 2 + 1, move);

                // third segment
                move += (m / 2 + 1) * (m / 2 + 1);
                segment->segments[2] = new Segment(m / 2 + 1, m / 2 + 1, i + m / 2 + 1, j + m / 2 - 1);
                solveClosedTourHelper(grid, segment->segments[2], i + m / 2 + 1, j + m / 2 - 1, m / 2 + 1, m / 2 + 1, move);

                // fourth segment
                move += (m / 2 + 1) * (m / 2 + 1);
                segment->segments[3] = new Segment(m / 2 + 1, m / 2 - 1, i + m / 2 + 1, j);
                solveClosedTourHelper(grid, segment->segments[3], i + m / 2 + 1, j, m / 2 + 1, m / 2 - 1, move);
            }
        }

        solveClosedTourMerge(grid, segment);
    }
}

void findPairs(Grid<int> &grid, Segment *segment, int section)
{
    int n = segment->segments[section]->n, m = segment->segments[section]->m;
    int k = segment->segments[section]->i, l = segment->segments[section]->j;
    vector<int> pairs;

    switch (section)
    {
        case 0:
        {
            for (int i = n - 4; i < n - 2; i++)
            {
                for (int j = m - 2; j < m; j++)
                {
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
                }
            }

            for (int i = n - 2; i < n; i++)
            {
                for (int j = m - 4; j < m; j++)
                {
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
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
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
                }
            }

            for (int i = n - 2; i < n; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
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
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
                }
            }

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
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
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
                }
            }

            for (int i = 0; i < 2; i++)
            {
                for (int j = m - 4; j < m; j++)
                {
                    // findPairsHelper(grid, segment, section, i, j);
                    pairs.push_back(grid[i + k][j + l]);
                }
            }

            break;
        }
        default:
        {
            break;
        }
    }

    sort(pairs.begin(), pairs.end());
    for (int i = 0; i < pairs.size() - 1; i++)
    {
        if (pairs[i] + 1 == pairs[i + 1])
        {
            segment->pairs[section][pairs[i]] = pairs[i + 1];
        }
    }
}

vector<int> intersection(const vector<int> &v1, const vector<int> &v2)
{
    unordered_set<int> s;
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                s.insert(v1[i]);
            }
        }
    }

    vector<int> inter;
    for (auto x : s)
    {
        inter.push_back(x);
    }

    return inter;
}

vector<int> getNeighbors(Grid<int> &grid, int i, int j)
{
    vector<int> v;
    for (int k = 0; k < 8; k++)
    {
        if (isValid(grid.getRows(), grid.getCols(), i + delta_i[k], j + delta_j[k]))
        {
            v.push_back(grid[i + delta_i[k]][j + delta_j[k]]);
        }
    }

    return v;
}

vector<int> findPath(Grid<int> &grid, Segment *segment)
{
    /*
     * Iterate over all starting locations for the search. We always start the
     * search from the entry point, and push the exit point into the stack
     * to then continue the search at the next segment
     */

    int counter = 0;
    for (auto &[x, y] : segment->pairs[0])
    {
        unordered_map<int, bool> visited;
        int entrance = x;
        int currSegment = 1;

        stack<vector<int>> s;
        vector<int> path, oldPath;

        if ((counter % 2) == 0)
        {
            path.push_back(entrance);
            path.push_back(segment->pairs[0][entrance]);
        }
        else
        {
            path.push_back(segment->pairs[0][entrance]);
            path.push_back(entrance);
            entrance = segment->pairs[0][entrance];
        }

        counter ^= 1;
        s.push(path);

        while (not s.empty())
        {
            path = s.top();

            if (oldPath.size() > path.size())
            {
                currSegment = (currSegment - (int)(oldPath.size() - path.size()) / 2) mod 4;

                for (int i = path.size(); i < oldPath.size(); i++)
                {
                    visited[oldPath[i]] = false;
                }
            }

            s.pop();

            int v = path[path.size() - 1];

            vector<int> validNbrs;
            for (auto x : segment->pairs[currSegment])
            {
                validNbrs.push_back(x.second);
                validNbrs.push_back(x.first);
            }

            validNbrs = intersection(getNeighbors(grid, grid(v)[0], grid(v)[1]), validNbrs);

            if (currSegment == 0)
            {
                for (int i = 0; i < validNbrs.size(); i++)
                {
                    if (validNbrs[i] == entrance)
                    {
                        path.push_back(entrance);
                        return path;
                    }
                }
            }
            else
            {
                oldPath = path;
                for (int i = 0; i < validNbrs.size(); i++)
                {
                    if (not visited[validNbrs[i]])
                    {
                        vector<int> np = path;
                        np.push_back(validNbrs[i]);

                        int nxt = -1;
                        for (auto x : segment->pairs[currSegment])
                        {
                            if (x.first == validNbrs[i])
                            {
                                nxt = x.second;
                                break;
                            }
                            else if (x.second == validNbrs[i])
                            {
                                nxt = x.first;
                                break;
                            }
                        }
                        np.push_back(nxt);

                        visited[validNbrs[i]] = true;
                        visited[nxt] = true;

                        s.push(np);
                    }
                }

                if (validNbrs.size())
                {
                    currSegment = (currSegment + 1) mod 4;
                }
            }
        }
    }

    return {};
}

void traverseSegments(Grid<int> &grid, Segment *segment, const vector<int> &path)
{
    Grid<int> copy = grid;

    int c = 1e9;
    for (int i = segment->i; i < segment->n + segment->i; i++)
    {
        for (int j = segment->j; j < segment->m + segment->j; j++)
        {
            c = min(c, grid[i][j]);
        }
    }

    for (int currSegment = 0; currSegment < segment->segments.size(); currSegment++)
    {
        int n = segment->segments[currSegment]->n, m = segment->segments[currSegment]->m;
        int i = segment->segments[currSegment]->i, j = segment->segments[currSegment]->j;

        int add = 1e9;
        for (int y = i; y < i + n; y++)
        {
            for (int x = j; x < j + m; x++)
            {
                add = min(add, grid[y][x]);
            }
        }

        int start = path[currSegment * 2] - add;

        do
        {
            copy[grid(start + add)[0]][grid(start + add)[1]] = c;
            copy(c++) = grid(start + add);

            if (segment->segments[currSegment]->rev) start--;
            else start++;
            start = start mod (segment->segments[currSegment]->n * segment->segments[currSegment]->m);
        } while (start != (path[currSegment * 2] - add));

        for (int y = i; y < i + n; y++)
        {
            for (int x = j; x < j + m; x++)
            {
                grid[y][x] = copy[y][x];
                grid(grid[y][x]) = {y, x};
            }
        }
    }
}

void solveClosedTourMerge(Grid<int> &grid, Segment *segment)
{
    /*
     * Search for pairs of indices that we can modify to create a closed path
     * between different segments
     */
    int n = segment->n, m = segment->m;
    int k = segment->i, l = segment->j;

    segment->pairs = PairMap(segment->segments.size());

    for (int i = 0; i < segment->segments.size(); i++)
    {
        findPairs(grid, segment, i);
    }

    // Find a path that connects 4 segments together
    vector<int> path = findPath(grid, segment);
    // assert(path.size() == 9);
    if (path.size() != 9)
    {
        return;
    }

    // Reverse paths accordingly
    for (int i = 0; i < path.size() - 1; i += 2)
    {
        if (path[i] == path[i + 1] - 1) segment->segments[i / 2]->rev = true;
    }

    traverseSegments(grid, segment, path);
}

void solveClosedTour(Grid<int> &grid)
{
    Segment *segment = new Segment(grid.getRows(), grid.getCols(), 0, 0);
    solveClosedTourHelper(grid, segment, 0, 0, grid.getRows(), grid.getCols(), 0);

    std::ofstream out("tours/" + std::to_string(grid.getRows()) + ".txt");
    out << "[\n";

    int j = 0;
    for (int i = 0; i < grid.getRows(); i++)
    {
        out << "[";
        for (j = 0; j < grid.getCols() - 1; j++)
        {
            out << grid[i][j] << ", ";
        }
        out << grid[i][j] << "],\n";
    }
    out << "],\n";

    out.close();
}
