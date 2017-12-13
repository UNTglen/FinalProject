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
	Date Modifide 20070125
		-Working on oveloading operator still
	Date Modifide 20070126
		-it was due and was given a second chance on life
		 Noticed my problem finally, and corrected it
		-Working on Multiplication, subtraction, and addition
		-compiles on my computer but not on the upload site
			- errors in test function
			- Matrix count wrong. 
****************************************************************************
class Matrix.h
	
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
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;



class Matrix 
{
private:
	//matrix dimensions
	int rows, cols; 

	//element array
	int **element; 

	//declares int matrixCount
	static int matrixCount;
public:

	//default 0x0 matrix
	Matrix(int r=0, int c=0); 

	//copy constructor
	Matrix(const Matrix&); 

	//Destructor
	~Matrix(); 

	//changes the meaning of "="
	Matrix operator=(Matrix&); 

	//changes the meaning of "[]"
	int* operator[](int n);
	
	//returns the number or rows
	int getRows() const; 

	//returns the number of cols
	int getColumns() const; 
	
	//returns the value of the element in r row and c column
	int getElement(int, int) const;

	//store the value (v) in the martix of location r,c
	void setElement(int, int, int) const;

	//return the sum of two matices
	Matrix add (const Matrix&) const;

	//return the diff of two matrices
	Matrix subtract (const Matrix&) const;

	//return the prod or two matricies
	Matrix multiply (const Matrix&) const;

	//return the value of matrixCount
	static int get_matrixCount();

};


#endif
