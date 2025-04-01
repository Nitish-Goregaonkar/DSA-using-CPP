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
    Matrix matrixmultiplication(Matrix m1,Matrix m2)//FRIEND FUNCTION to multiply matrices
    {
        int i,j,k,p;
        p=m1.col;
        Matrix m3(m1.row,m2.col);
        for(i=0;i<m3.row;i++)
        {
            for(j=0;j<m3.col;j++)
            {
                m3.getElement(i,j,0);
                for(k=0;k<p;k++)
                {
                    m3.ptrToMatrix[i][j]=m3.ptrToMatrix[i][j]+(m1.ptrToMatrix[i][k])*(m2.ptrToMatrix[k][j]);
                }
            }
        }
        return (m3);
    }
    
    int main()//main function
    {
        int i,j,r,c,value;
        cout<<"Enter the dimension of first matrix\n";
        cin>>r>>c;
        Matrix mat1(r,c);
        cout<<"Enter the elements of first matrix row by row\n";
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cin>>value;
                mat1.getElement(i,j,value);
            }
        }
    }
    cin >> r >> c;
Matrix mat2(r, c);
cout << "Enter the elements of second matrix row by row\n";
for (i = 0; i < r; i++)
{
    for (j = 0; j < c; j++)
    {
        cin >> value;
        mat2.setElement(i, j, value);
    }
}
Matrix mat3(mat1.row, mat2.col); // matrix to store the product
mat3 = matrixMultiplication(mat1, mat2);
for (i = 0; i < mat3.row; i++)
{
    for (j = 0; j < mat3.col; j++)
    {
        cout << mat3.display[i][j] << "\t";
    }
    cout << "\n";
}
return 0;
