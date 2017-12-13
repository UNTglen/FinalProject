#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

ostream& printMatrix(Matrix m, ostream& out);
void TestFunction1(Matrix, Matrix, Matrix);



int main(void)
{

//check to see if the static variable matrixCount has been created and init

    cout << "matrixCount = " << Matrix::get_matrixCount() << endl;
    cout << "(matrixCount should be zero)\n\n";
    
    
//create 3 matrices, check matrixCount, .and print matrix dimension

    Matrix A,B(5,3),C(3,7);
    
    A = B;
    
    cout << "Matrix A\n";
    cout << "\t Rows = " << A.getRows()    << endl;
    cout << "\t Cols = " << A.getColumns() << endl;

    cout << "Matrix B\n";
    cout << "\t Rows = " << B.getRows()    << endl;
    cout << "\t Cols = " << B.getColumns() << endl;

    cout << "Matrix C\n";
    cout << "\t Rows = " << C.getRows()    << endl;
    cout << "\t Cols = " << C.getColumns() << endl;


    cout << endl;
    cout << "matrixCount = " << Matrix::get_matrixCount() << endl;
    cout << "(matrixCount should be three (3))\n\n";
    
//Test the copy constructor and destructor
    cout << endl;
    cout << "matrixCount = " << Matrix::get_matrixCount() << endl;
    cout << "(before call the TestFunction1)\n\n";

    TestFunction1(A,B,C);
    
    cout << endl;
    cout << "matrixCount = " << Matrix::get_matrixCount() << endl;
    cout << "(after call the TestFunction1)\n\n";
    

//create some data arrays

	int row, col, index;
	int data1[]={-1,2,-3,4,-5,6,-7,8,-9,10,-11,12,-13,14,-15};
	int data2[]={0,2,0,4,0,6,0,8,0,10,0,12,0,14,0};
	int data3[]={-5,-10,-15,0,5,10,15,
                     36,42,-5,-10,-15,0,5,
                     10,15,36,42,6,-19,7};
	
	

//Fill Matricies A, B will initial values
//Test setElement
	index = 0;
	for(row = 0; row < 5; row++)
	  for(col = 0 ; col < 3; col++)
	  {
	    A.setElement(row, col, data1[index]);
	    B.setElement(row,col,data2[index]);
	    index++;
	  }

//Fill Matricies C will initial values
//Test overloaded []
    index = 0;
	for(row = 0; row < 3; row++)
	  for(col = 0 ; col < 7; col++)
	  {
	    C[row][col] = data3[index++];
	  }


//Print Matricies A, B, C

	cout<<"Matrix A\n\n";
	printMatrix(A,cout);
    cout << endl << endl;
    
	cout<<"Matrix B\n\n";
	printMatrix(B,cout);
    cout << endl << endl;
    
	cout<<"Matrix C\n\n";
	printMatrix(C,cout);
    cout << endl << endl;
    
   

//Addition

	cout << "Matrix A + B\n\n";
	printMatrix(A.add(B),cout);
    cout << endl << endl;
    



//Test Subtraction

	cout<<"Matrix A - B\n\n";
	printMatrix(A.subtract(B),cout);
    cout << endl << endl;
    



//Test Multiplication	
    
 	cout<<"Matrix A * C\n\n";
	printMatrix(A.multiply(C),cout);
    cout << endl << endl;
    
 //Test the operator= function
     cout << "Matrix A = C " << endl << endl;
     A = C;
     cout << "Matrix A\n\n";
     
     printMatrix(A, cout);
     
     cout << "Matrix C \n\n";
     
     printMatrix(C, cout);
 
	return 0;

  }




//Function to print a Matrix

ostream& printMatrix(Matrix m, ostream& out)
{
    int row, col;
    int r,c;
    
    row = m.getRows();
    col = m.getColumns();
  
  	for(r = 0; r < row; r++)
	{
	  for(c = 0 ; c < col; c++)
	    out <<setw(4)<< m.getElement(r, c)<<" ";
	  out<<endl;
	}
    return out;
}


//Test Function 1, test copy constructor
void TestFunction1(Matrix x, Matrix y, Matrix z)
{
    cout << endl;
    cout << "matrixCount = " << Matrix::get_matrixCount() << endl;
    cout << "(In TestFunction1)\n\n";
   
   
   return;
}

