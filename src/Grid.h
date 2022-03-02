#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Grid
{

public:
    Grid();
    Grid(int n, int m);
    Grid(int n, int m, T val);
    ~Grid();

    void print(ostream &out=cout);

    int getRows();
    int getCols();

    vector<T> &operator[](int i);
    
private:
    vector<vector<T>> grid;
};

template <typename T>
Grid<T>::Grid()
{

}

template <typename T>
Grid<T>::Grid(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        grid.push_back(vector<T>(m));
    }
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
int Grid<T>::getRows()
{
    return grid.size();
}

template <typename T>
int Grid<T>::getCols()
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