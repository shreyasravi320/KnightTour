#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Grid
{

public:
    Grid();
    Grid(int n, int m, T val);
    ~Grid();
    Grid(vector<vector<T>> &rhs);

    void print(ostream &out=cout);

    int getRows() const;
    int getCols() const;

    vector<T> &operator[](int i);
    Grid<T> &operator=(const vector<vector<T>> &rhs);
    
private:
    vector<vector<T>> grid;
};

template <typename T>
Grid<T>::Grid()
{

}

template <typename T>
Grid<T>::Grid(int n, int m, T val)
{
    for (int i = 0; i < n; i++)
    {
        grid.push_back(vector<T>(m, val));
    }
}

template <typename T>
Grid<T>::~Grid()
{

}

template <typename T>
Grid<T>::Grid(vector<vector<T>> &rhs)
{
    if (grid != rhs)
    {
        grid = rhs;
    }
}

template <typename T>
Grid<T> &Grid<T>::operator=(const vector<vector<T>> &rhs)
{
    if (grid != rhs)
    {
        grid = rhs;
    }

    return *this;
}

template <typename T>
int Grid<T>::getRows() const
{
    return grid.size();
}

template <typename T>
int Grid<T>::getCols() const
{
    return grid[0].size();
}

template <typename T>
void Grid<T>::print(ostream &out)
{
    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getCols(); j++)
        {
            out << grid[i][j] << "\t";
        }

        out << "\n";
    }
}

template <typename T>
vector<T> &Grid<T>::operator[](int i)
{
    return grid[i];
}

#endif