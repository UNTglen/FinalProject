/**************************************************************************
	File name: Matrix.h
	Author: Glen Newell
	Assignment Title: Matrix Class
	Assignment Description: To build a matix Class that will copy, count,
	add, subtract, and multiply elements within the class
	Due Date: 20070126
	Date Created: 20070122

	Date Modifide: 20070122
		-File Created
	Date Modifide: 20070122
		-Completed Basic Sturcture 
	Date Modifide: 20070123
		-Worked on the Matrix functions.
	Date Modifide: 20070123
		-Contiued to Worked on the Matrix functions.
	Date Modifide: 20070124
		-Correcting overloading = operator
	Date Modifide  20070125
		-Working on oveloading operator still
	Date Modifide  20070126
		-it was due and was given a second chance on life
		 Noticed my problem finally, and corrected it
		-Working on Multiplication, subtraction, and addition
		-compiles on my computer but not on the upload site
			- errors in test function
			- Matrix count wrong. 
	Date Modifide  20070128
		-Solution works on my computer not on upload?
			-no matching function for call to `Matrix::Matrix()'

****************************************************************************
class Matrix.cpp
	
	Function: Matrix::Matrix(int, int)
	Type: Default Constructor
	Description: Dynamically allicates memory and increments matrixCount

	Function: Matrix::Matrix(const Matrix&)
	Type:Default: Copy COnstructor
	Description: Creats a copy of any given Matrix

	Function: ~Matrix()
	Type: Destructor
	Description:De-allocates memory and decrements matrixCount

	Function: Matrix operator= (Matrix)
	Type: Overloades assignment operator
	Description:Returns a copy of Matrix

	Function: int* Operator[] (int n)
	Type: overlades square brackets '[]'
	Description:Returns the nth intager pointer

	Function: int getRows() const
	Type: get function
	Description:Returns number of rows in matrix

	Function: int getColumns() const
	Type: get function
	Description:Returns number of cols in matrix

	Function: int getElement(int r, int c) const
	Type: get function
	Description:Returns the value in the element r row and c column

	Function: void setElement (int r, int c, int v)
	Type: set function
	Description:Stores the value of v in to the matrix location r, c

	Function: Matrix add (conts Matrix& m) const
	Type: Adding
	Description: returns the sum of two matricies

	Function: Matrix subtract (conts Matrix& m) const
	Type: Subtraction
	Description: returns the difference of two matricies

	Function: Matrix multiply (conts Matrix& m) const
	Type: Multiplication
	Description: returns the product of two matricies

	Function: static int get_matrixCount();
	Type: get
	Description: returns the value of matrixCount:


***************************************************************************/
#include "Matrix.h"

//initializes matrixCount to 0
int Matrix::matrixCount=0;

Matrix::Matrix(int r, int c)
{
	matrixCount++;
	rows = r;
	cols = c;
	element = NULL;
	if(rows*cols > 0 && cols > 0)
	{
		element = new int* [rows];
		for(r=0; r<rows; r++)
		{
			element[r] = new int[cols];

			for(int c1 = 0; c1 < cols; c1++)
			{
				element[r][c1]=0;
			}
		}

	}
}


Matrix::Matrix(const Matrix& m)
{
	matrixCount++;
	rows = m.rows;
	cols = m.cols;

	if(rows > 0 && cols > 0)
	{
		element = new int* [rows];
		for(int r=0; r<rows; r++)
		{
			element[r] = new int [cols];
		}

		for(int r1 = 0; r1 < rows; r1++)
		{
			for(int c = 0; c <= cols; c++)
				{
					element[r1][c] = m.element[r1][c];
				}
		}
	}
}



Matrix::~Matrix()
{

	delete[] element;
	matrixCount--;
}



Matrix Matrix::operator=(Matrix& m)
{	
	for(int r1 = 0; r1 < rows; r1++)
	{
		delete[] element[r1];
	}
	delete[] element;
	rows=m.rows;
	cols=m.cols;
	element = NULL;

	if(rows > 0 && cols > 0)
	{
		element = new int* [rows];
		for(int r=0; r<rows; r++)
		{
			element[r] = new int [cols];
		}

		for(int r1 = 0; r1 < rows; r1++)
		{
			for(int c = 0; c <= cols; c++)
				{
					element[r1][c] = m.element[r1][c];
				}
		}
	}
	
	return *this;
}


int Matrix::getRows() const
{
	return rows;
}


int Matrix::getColumns() const
{
	return cols;
}

int* Matrix::operator [](int n)
{
	return element[n];
}


int Matrix::getElement(int r, int c) const
{
	return element[r][c];
}

//sets v to the meaning of element[r][c] 
void Matrix::setElement(int r, int c, int v)  const 
{
	element[r][c]=v;
}

Matrix Matrix::add(const Matrix& m) const
{
	//matrix to be returned
	Matrix newMatrix(rows, m.cols);
	if(rows > 0 && cols > 0)
	{
		for(int r1 = 0; r1 < rows; r1++)
		{
			for(int c = 0; c <= cols; c++)
				{
					newMatrix[r1][c] = element[r1][c] + m.element[r1][c];
				}
		}
	}
 	return newMatrix;
}

Matrix Matrix::subtract(const Matrix& m) const
{
	//matrix to be returned
	Matrix newMatrix (rows, m.cols);
	if(rows > 0 && cols > 0)
	{
		for(int r1 = 0; r1 < rows; r1++)
		{
			for(int c = 0; c <= cols; c++)
				{
					newMatrix[r1][c] = element[r1][c] - m.element[r1][c];
				}
		}
	}
	return newMatrix;
}

Matrix Matrix::multiply(const Matrix& m) const
{
	
	Matrix newMatrix(rows, m.cols); 
 	int tempRow; 
 	int tempCol, tempCol2; 
 	int	tempAns; 
	
	for(tempRow = 0; tempRow<rows; tempRow++) 
 	{	
 		for(tempCol = 0; tempCol<cols; tempCol++)
 			{
 				tempAns = 0; //initiallizes tempAns to 0
 				for(tempCol2=0; tempCol2<cols; tempCol2++)
 				{
					tempAns += ((element[tempRow][tempCol2])*(m.element[tempCol2][tempCol]));
 				}
			newMatrix[tempRow][tempCol]=tempAns;
			}
		}
 	return newMatrix;
}

int Matrix::get_matrixCount()
{	
	return matrixCount;
	
}
