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
