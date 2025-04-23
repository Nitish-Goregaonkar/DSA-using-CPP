#include <iostream>
using namespace std;

class Matrix // Class definition
{
    int **ptrToMatrix; // Pointer to a 2D array
    int row, col;

public:
    // Constructor to allocate space for matrix
    Matrix(int x, int y)
    {
        row = x;
        col = y;
        ptrToMatrix = new int *[row];
        for (int i = 0; i < row; i++)
        {
            ptrToMatrix[i] = new int[col];
        }
    }

    // Getter functions for row and column
    int getRow() const { return row; }
    int getCol() const { return col; }

   