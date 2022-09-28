#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>

using namespace std;

template <typename T>
class Grid
{

public:
    Grid();
    Grid(int n, int m, T val);
    ~Grid();
    Grid(vector<vector<T>> &rhs);
    Grid(const Grid<T> &rhs);

    void print(ostream &out=cout);

    int getRows() const;
    int getCols() const;

    Grid<T> &operator=(const vector<vector<T>> &rhs);
    Grid<T> &operator=(const Grid<T> &rhs);
    vector<T> &operator[](int i);
    array<int, 2> &operator()(int i);

private:
    vector<vector<T>> grid;
    unordered_map<T, array<int, 2>> cells;
};

template <typename T>
Grid<T>::Grid()
{
    grid = vector<vector<T>>();
    cells = unordered_map<T, array<int, 2>>();
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
    grid = vector<vector<T>>(rhs.size());
    for (int i = 0; i < rhs.size(); i++)
    {
        vector<T> v(rhs[0].size());
        for (int j = 0; j < rhs[0].size(); j++)
        {
            grid[i][j] = rhs[i][j];
        }
    }
    cells.clear();

    for (int i = 0; i < rhs.size(); i++)
    {
        for (int j = 0; j < rhs[0].size(); j++)
        {
            cells[grid[i][j]] = {i, j};
        }
    }
}

template <typename T>
Grid<T>::Grid(const Grid<T> &rhs)
{
    grid = vector<vector<T>>(rhs.getRows());
    for (int i = 0; i < rhs.getRows(); i++)
    {
        vector<T> v(rhs.getCols());
        for (int j = 0; j < rhs.getCols(); j++)
        {
            v[j] = rhs.grid[i][j];
        }
        grid[i] = v;
    }
    cells.clear();

    for (int i = 0; i < rhs.getRows(); i++)
    {
        for (int j = 0; j < rhs.getCols(); j++)
        {
            cells[grid[i][j]] = {i, j};
        }
    }
}

template <typename T>
Grid<T> &Grid<T>::operator=(const vector<vector<T>> &rhs)
{
    grid = vector<vector<T>>(rhs.size());
    for (int i = 0; i < rhs.size(); i++)
    {
        vector<T> v(rhs[0].size());
        for (int j = 0; j < rhs[0].size(); j++)
        {
            v[j] = rhs[i][j];
        }
        grid[i] = v;
    }
    cells.clear();

    for (int i = 0; i < rhs.size(); i++)
    {
        for (int j = 0; j < rhs[0].size(); j++)
        {
            cells[grid[i][j]] = {i, j};
        }
    }

    return *this;
}

template <typename T>
Grid<T> &Grid<T>::operator=(const Grid<T> &rhs)
{
    grid = vector<vector<T>>(rhs.getRows());
    for (int i = 0; i < rhs.getRows(); i++)
    {
        vector<T> v(rhs.getCols());
        for (int j = 0; j < rhs.getCols(); j++)
        {
            v[j] = rhs.grid[i][j];
        }

        grid[i] = v;
    }
    cells.clear();

    for (int i = 0; i < rhs.getRows(); i++)
    {
        for (int j = 0; j < rhs.getCols(); j++)
        {
            cells[grid[i][j]] = {i, j};
        }
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
            out << grid[i][j] << ",\t";

            if (getRows() >= 10 and grid[i][j] < 100)
            {
                out << "\t";
            }
        }
        out << "\n";
    }

    // out << "\n";
    // for (int i = 0; i < getRows() * getCols(); i++)
    // {
    //     out << i << ": { " << cells[i][0] << ", " << cells[i][1] << " }\n";
    // }
    // out << "\n";
}

template <typename T>
vector<T> &Grid<T>::operator[](int i)
{
    return grid[i];
}

template <typename T>
array<int, 2> &Grid<T>::operator()(int i)
{
    return cells[i];
}

#endif
