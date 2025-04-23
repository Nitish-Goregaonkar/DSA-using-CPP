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

    // Function to assign values to the matrix
    void setElement(int r, int c, int value)
    {
        ptrToMatrix[r][c] = value;
    }

    // Function to retrieve values from the matrix
    int getElement(int r, int c) const
    {
        return ptrToMatrix[r][c];
    }

    // Friend function for matrix multiplication
    friend Matrix matrixMultiplication(const Matrix &m1, const Matrix &m2);

    // Destructor to free allocated memory
    ~Matrix()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] ptrToMatrix[i];
        }
        delete[] ptrToMatrix;
    }
};

// Friend function to multiply matrices
Matrix matrixMultiplication(const Matrix &m1, const Matrix &m2)
{
    if (m1.getCol() != m2.getRow())
    {
        throw invalid_argument("Matrix dimensions do not match for multiplication.");
    }

    Matrix m3(m1.getRow(), m2.getCol());
    for (int i = 0; i < m3.getRow(); i++)
    {
        for (int j = 0; j < m3.getCol(); j++)
        {
            m3.setElement(i, j, 0); // Initialize to 0
            for (int k = 0; k < m1.getCol(); k++)
            {
                m3.ptrToMatrix[i][j] += m1.ptrToMatrix[i][k] * m2.ptrToMatrix[k][j];
            }
        }
    }
    return m3;
}

int main() // Main function
{
    int i, j, r, c, value;

    // Input first matrix
    cout << "Enter the dimensions of the first matrix (rows and columns): ";
    cin >> r >> c;
    Matrix mat1(r, c);
    cout << "Enter the elements of the first matrix row by row:\n";
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> value;
            mat1.setElement(i, j, value);
        }
    }

    // Input second matrix
    cout << "Enter the dimensions of the second matrix (rows and columns): ";
    cin >> r >> c;
    Matrix mat2(r, c);
    cout << "Enter the elements of the second matrix row by row:\n";
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> value;
            mat2.setElement(i, j, value);
        }
    }

    // Multiply matrices
    try
    {
        Matrix mat3 = matrixMultiplication(mat1, mat2);
        cout << "Resultant matrix:\n";
        for (i = 0; i < mat3.getRow(); i++)
        {
            for (j = 0; j < mat3.getCol(); j++)
            {
                cout << mat3.getElement(i, j) << "\t";
            }
            cout << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
