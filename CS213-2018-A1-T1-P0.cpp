// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//Supportin fucnctions
void getX_Y (int& x, int& y ,int n);
void getX_Scalar (int& x, int& scalar ,int n);
void getX (int& x ,int n);
void newEmptyMat(matrix& mat , int row , int col);
//__________________________________________

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {1,2,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int n=3;
    matrix mat[20];
    createMatrix (4, 2, data1, mat[0]);
    createMatrix (2, 3, data2, mat[1]);
    createMatrix (4, 2, data3, mat[2]);
    // The next code will not work until you write the functions
    cout << "The program have 3 matrices in defualt" << endl;
    cout << "Mat1" << endl << mat[0] << endl;
    cout << "Mat2" << endl << mat[1] << endl;
    cout << "Mat3" << endl << mat[2] << endl;
    while (1==1)
    {
        string choice;
        cout << "The program now have " << n << " matrices\nWhat do you want to do" << endl << endl;
        cout << "Student #1" << endl;
        cout << "1- MatX + MatY\n2- MatX - MatY\n3- MatX * MatY\n4- MatX + scalar\n5- MatX - scalar\n6- MatX * scalar" << endl;
        cout << "Student #2" << endl;
        cout << "7- MatX += MatY\n8- MatX -= MatY\n9- MatX += scalar\n10- MatX -= scalar\n11- ++MatX\n12- --MatX\n13- Enter a new matrix" << endl;
        cout << "Student #3" << endl;
        cout << "14- Print MatX\n15- MatX == MatY\n16- MatX != MatY\n17- MatX is square\n18- MatX is symetric\n19- MatX is identity\n20- Transpose Matx" << endl;
        cout << "\n21- Show all the stored matrices\n0- Close the program" << endl;
        cin >> choice;
        int x,y,scalar;
        bool chek;
        if (choice=="1")//MatX + MatY
        {
            getX_Y(x,y,n);
            cout << (mat[x-1]+mat[y-1]);
        }
        else if (choice=="2")//MatX - MatY
        {
            getX_Y(x,y,n);
            cout << (mat[x-1]-mat[y-1]);
        }
        else if (choice=="3")//MatX * MatY
        {
            getX_Y(x,y,n);
            cout << (mat[x-1]*mat[y-1]);
        }
        else if (choice=="4")//MatX + n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]+scalar);
        }
        else if (choice=="5")//MatX - n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]-scalar);
        }
        else if (choice=="6")//MatX * n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]*scalar);
        }
        else if (choice=="7")//MatX += MatY
        {
            getX_Y(x,y,n);
            cout << (mat[x-1]+=mat[y-1]);
        }
        else if (choice=="8")//MatX -= MatY
        {
            getX_Y(x,y,n);
            cout << (mat[x-1]-=mat[y-1]);
        }
        else if (choice=="9")//MatX += n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]+=scalar);
        }
        else if (choice=="10")//MatX -= n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]-=scalar);
        }
        else if (choice=="11")//++MatX
        {
            getX(x,n);
            ++mat[x-1];
            cout << mat[x-1];
        }
        else if (choice=="12")//--MatX
        {
            getX(x,n);
            --mat[x-1];
            cout << mat[x-1];
        }
        else if (choice=="13")//Enter new matrix
        {
            ++n;
            cin >> mat[n-1];
            cout << "Mat" << n << endl << mat[n-1] << endl;
        }
        else if (choice=="14")//Print MatX
        {
            getX(x,n);
            cout << mat[x-1];
        }
        else if (choice=="15")//MatX == MatY
        {
            getX_Y(x,y,n);
            cout << (mat[x-1] == mat[y-1]) <<endl;
        }
        else if (choice=="16")//MatX != MatY
        {
            getX_Y(x,y,n);
            cout << (mat[x-1] != mat[y-1]) <<endl;
        }
        else if (choice=="17")//MatX is square
        {
            getX(x,n);
            cout << (isSquare(mat[x-1])) <<endl;
        }
        else if (choice=="18")//MatX is symetric
        {
            getX(x,n);
            cout << (isSymetric(mat[x-1])) <<endl;
        }
        else if (choice=="19")//MatX is identity
        {
            getX(x,n);
            cout << (isIdentity(mat[x-1])) <<endl;
        }
        else if (choice=="20")//Transpose MatX
        {
            getX(x,n);
            cout << (transpose(mat[x-1]));
        }
        else if (choice=="21")//Show all the stored matrices
        {
            for (int i=0 ; i<n ; i++)
                cout << "Mat" << i+1 << endl << mat[i] << endl;
        }
        else if (choice=="0")//Close the program
            return 0;
        else
            cout << "Please choose from 0 to 21 only" << endl;
    }
    return 0;
}
//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];
    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
    }
}
// Student #1 with the middle ID (20170120)
matrix operator+  (matrix mat1, matrix mat2) // Add if same dimensions
{
    if (mat1.row==mat2.row && mat1.col== mat2.col)
    {
        matrix mat;
        newEmptyMat(mat,mat1.row,mat1.col);
        for (int i=0 ; i<mat.row ; i++)
        {
            for (int j=0 ; j<mat.col ; j++)
                mat.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
        }
        return mat;

    }
    else
        cout << "Matrices are not equal in dimentions" << endl;
}
matrix operator-  (matrix mat1, matrix mat2) // Sub if same dimensions
{
    if (mat1.row==mat2.row && mat1.col== mat2.col)
    {
        matrix mat;
        newEmptyMat(mat,mat1.row,mat1.col);
        for (int i=0 ; i<mat.row ; i++)
        {
            for (int j=0 ; j<mat.col ; j++)
                mat.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
        }
        return mat;

    }
    else
        cout << "Matrices are not equal in dimentions" << endl;
}
matrix operator*  (matrix mat1, matrix mat2) // Multi if col1 == row2
{
    if (mat1.col==mat2.row)
    {
        matrix mat;
        newEmptyMat(mat,mat1.row,mat2.col);
        for (int i=0 ; i<mat.row ; i++)
        {
            for (int j=0 ; j<mat.col ; j++)
            {
                mat.data[i][j]=0;
                for (int k=0 ; k<mat1.col ; k++)
                    mat.data[i][j]+=mat1.data[i][k]*mat2.data[k][j];
            }

        }
        return mat;
    }
    else
        cout << "number of col in MatX must equal number of row in MatY" << endl;
}
matrix operator+  (matrix mat1, int scalar)  // Add a scalar
{
    matrix mat;
    newEmptyMat(mat,mat1.row,mat1.col);
    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
            mat.data[i][j]=mat1.data[i][j]+scalar;
    }
    return mat;
}
matrix operator-  (matrix mat1, int scalar)  // Subtract a scalar
{
    matrix mat;
    newEmptyMat(mat,mat1.row,mat1.col);
    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
            mat.data[i][j]=mat1.data[i][j]-scalar;
    }
    return mat;
}
matrix operator*  (matrix mat1, int scalar)  // Multiple by scalar
{
    matrix mat;
    newEmptyMat(mat,mat1.row,mat1.col);
    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
            mat.data[i][j]=mat1.data[i][j]*scalar;
    }
    return mat;
}
// Student #2 with the middle ID (20170195)
matrix operator+= (matrix& mat1, matrix mat2)
{
    if (mat1.row==mat2.row && mat1.col== mat2.col)
    {
        for (int i=0 ; i<mat1.row ; i++)
        {
            for (int j=0 ; j<mat1.col ; j++)
                mat1.data[i][j]+=mat2.data[i][j];
        }
        return mat1;
    }
    else
        cout << "Matrices are not equal in dimentions" << endl;
}
matrix operator-= (matrix& mat1, matrix mat2)
{
    if (mat1.row==mat2.row && mat1.col== mat2.col)
    {
        for (int i=0 ; i<mat1.row ; i++)
        {
            for (int j=0 ; j<mat1.col ; j++)
                mat1.data[i][j]-=mat2.data[i][j];
        }
        return mat1;
    }
    else
        cout << "Matrices are not equal in dimentions" << endl;
}
matrix operator+= (matrix& mat, int scalar)
{
    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
            mat.data[i][j]+=scalar;
    }
    return mat;
}
matrix operator-= (matrix& mat, int scalar)
{
    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
            mat.data[i][j]-=scalar;
    }
    return mat;
}
void   operator++ (matrix& mat)   	// Add 1 to each element ++mat
{
    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
            mat.data[i][j]++;
    }
}
void   operator-- (matrix& mat)    	// Sub 1 from each element --mat
{
    for (int i=0 ; i<mat.row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
            mat.data[i][j]--;
    }
}
istream& operator>> (istream& in, matrix& mat)
{
    int row,col;
    cout << "Enter the number of rows and colomns :";
    cin >> row >> col;
    int data[row*col];
    for (int i=0 ; i<row*col ; i++)
            cin >> data[i];
    createMatrix(row,col,data,mat);
    return in;
}
// Student #3 with the middle ID (20170201)
ostream& operator<< (ostream& out, matrix mat)
{
    for (int i=0; i<mat.row; i++)
    {
        out << "|";
        for (int j=0; j<mat.col; j++)
            out << setw(3) << mat.data[i][j] << " ";
        out << "|" << endl;
    }
    return out;
}
bool operator == (matrix mat1 , matrix mat2)
{
    bool x = true;
    if (mat1.row==mat2.row && mat1.col==mat2.col)
    {
        for (int i=0 ; i<mat1.row ; i++)
        {
            for (int j=0 ; j<mat1.col ; j++)
            {
                if (mat1.data[i][j] != mat2.data[i][j])
                {
                    x = false;
                    break;
                }
            }
        }
        return x;
    }
    else
        cout << "The matrices are not equal in dimentions" << endl;
}
bool operator != (matrix mat1 , matrix mat2)
{
    bool x = false;
    if (mat1.row==mat2.row && mat1.col==mat2.col)
    {
        for (int i=0 ; i<mat1.row ; i++)
        {
            for (int j=0 ; j<mat1.col ; j++)
            {
                if (mat1.data[i][j] != mat2.data[i][j])
                {
                    x = true;
                    break;
                }
            }
        }
        return x;
    }
    else
        cout << "The matrices are not equal in dimentions" << endl;
}
bool isSquare (matrix mat)
{
    bool x = true;
    if (mat.row != mat.col)
        x = false;
    return x;
}
bool isSymetric (matrix mat)
{
    bool x = false;
    if (isSquare(mat) == true)
    {
        x = true;
        for (int i=0 ; i<mat.row ; i++)
        {
            for (int j=0 ; j<mat.col ; j++)
                {
                    if (mat.data[i][j] != mat.data[j][i])
                        x = false;
                        break;
                }
        }
    }
    return x;
}
bool isIdentity (matrix mat)
{
    bool x = false;
    if (isSquare(mat) == true)
    {
        x = true;
        for (int i=0 ; i<mat.row ; i++)
        {
            for (int j=0 ; j<mat.col ; j++)
            {
                if (i==j && mat.data[i][j] != 1)
                {
                    x=false;
                    break;
                }
                if (i!=j && mat.data[i][j] != 0)
                {
                    x = false;
                    break;
                }
            }
        }
    }
    return x;
}
matrix transpose(matrix mat)
{
    matrix mat1;
    newEmptyMat(mat1,mat.col,mat.row);
    for (int i=0 ; i<mat1.row ; i++)
    {
        for (int j=0 ; j<mat1.col ; j++)
            mat1.data[i][j] = mat.data[j][i];
    }
    return mat1;
}
//Supporting functions
void getX_Y (int& x, int& y ,int n)
{
    cout << "Enter the number of matrices you want to use" << endl;
    cout << "X=";
    cin >> x;
    cout << "Y=";
    cin >> y;
    while (x<1 || x>n || y<1 || y>n)
    {
        cout << "There is only " << n << " matrices, you must choose from 1 to " << n << endl;
        getX_Y(x,y,n);
    }
}
void getX_Scalar (int& x, int& scalar ,int n)
{
    cout << "Enter the number of matrix you want to use and the scalar" << endl;
    cout << "X=";
    cin >> x;
    cout << "scalar=";
    cin >> scalar;
    while (x<1 || x>n)
    {
        cout << "There is only " << n << " matrices, you must choose from 1 to " << n << endl;
        getX_Scalar(x,scalar,n);
    }
}
void getX (int& x ,int n)
{
    cout << "Enter the number of matrix you want to use" << endl;
    cout << "X=";
    cin >> x;
    while (x<1 || x>n)
    {
        cout << "There is only " << n << " matrices, you must choose from 1 to " << n << endl;
        getX(x,n);
    }
}
void newEmptyMat(matrix& mat , int row , int col)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [mat.row];
    for (int i=0 ; i<mat.row ; i++)
        mat.data[i] = new int [mat.col];
}
