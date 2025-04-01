#include<iostream>
using namespace std;
class Matrix     // Class definition
{
    int *ptrToMatrix;
    int row, col;

public:
    Matrix(int x, int y);
    void getElement(int r, int c, int value) // function to get values in matrix
    {
        ptrToMatrix[r][c] = value;
    }

    int &display(int r, int c) // function to display values in matrix
    {
        return (ptrToMatrix[r][c]);
    }

    friend Matrix matrixMultiplication(Matrix, Matrix);

    Matrix::Matrix(int x, int y) // CONSTRUCTOR to allocate space to each row in matrix
    {
        row = x;
        col = y;
        ptrToMatrix = new int *[row];

        for (int i = 0; i < row; i++)
            ptrToMatrix[i] = new int[col];
    }
