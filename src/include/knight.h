#ifndef KNIGHT_H
#define KNIGHT_H

#include "grid.h"

#include <unordered_set>
#include <unordered_map>
#include <stack>

#define UNVISITED -1
#define PairMap vector<unordered_map<int, unordered_set<int>>>

/*
 * Necessary base cases
 * we need the 6x6, 6x8, 8x8, 8x10, and 10x10 boards to be solved closed
 * knight tours to guarantee an NxN board (N is even and greater than 6)
 */
extern Grid<int> SOLUTION_6x6;
extern Grid<int> SOLUTION_6x8;
extern Grid<int> SOLUTION_8x8;
extern Grid<int> SOLUTION_8x10;
extern Grid<int> SOLUTION_10x10;
extern Grid<int> SOLUTION_10x12;

/*
 * Segment struct
 * Purpose: recursive data structure to hold 4 sections of the board
 *          with sub-boards for board larger than 10 x 10
 */
struct Segment
{
    int n;
    int m;
    int i;
    int j;

    bool reversed = false;

    vector<Segment *> segments;
    PairMap pairs;

    Segment()
    {
        segments = vector<Segment *>();
        pairs = PairMap();
    }

    Segment(int _n, int _m, int _i, int _j)
    {
        n = _n;
        m = _m;
        i = _i;
        j = _j;

        segments = vector<Segment *>();
        pairs = PairMap();
    }

    ~Segment()
    {
        for (int i = 0; i < segments.size(); i++)
        {
            delete segments[i];
        }
    }

    void print()
    {
        if ((n <= 12 and m <= 10) or (n <= 10 and m <= 12))
        {
            cout << "Height: " << n << ", Width: " << m << "; Starts at " << i << ", " << j << "\n";
        }

        else
        {
            for (int i = 0; i < segments.size(); i++)
            {
                segments[i]->print();
            }
        }
    }
};

/*
 * isValid
 * Purpose: check if a cell [i, j] is contained within the board
 * Parameters: dimensions of the board, index pair i, j
 * Returns: true if [i, j] is within the board, false otherwise
 */
bool isValid(int n, int m, int i, int j);

/*
 * populateSolutions
 * Purpose: populate the necessary base cases with hard-coded solutions
 * Parameters: None
 * Returns: None
 */
void populateSolutions();

/*
 * solveClosedTourHelper
 * Purpose: solve knight's tour sub-problems for sections of any board
 * Parameters: board, segment, start indices, size of the board
 * Returns: None
 */
void solveClosedTourHelper(Grid<int> &grid, Segment &segment, int i, int j, int n, int m, int move);

void findPairsHelper(Grid<int> &grid, Segment &segment, int section, int i, int j);

/*
 * findPairs
 * Purpose: Search for pairs of indices that we can modify to create a 
 *          closed path between different segments
 * Parameters: board to search on, segments to search on, section of the 
 *             board to iterate over
 * Returns: None
 */
void findPairs(Grid<int> &grid, Segment &segment, int section);

/*
 * solveClosedTourMerge
 * Purpose: merge solved knight's tour sections for the entire board
 * Parameters: board divided into subsections
 * Returns: None
 */
void solveClosedTourMerge(Grid<int> &grid, Segment &segment);

/*
 * solveClosedTour
 * Purpose: solve the knight's tour problem for a n by n board
 * Parameters: a grid representing the board to solve
 * Returns: None
 */
void solveClosedTour(Grid<int> &grid);

#endif