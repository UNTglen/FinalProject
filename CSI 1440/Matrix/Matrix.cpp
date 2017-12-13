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
	this->rows = m.rows;
	this->cols = m.cols;

	if(rows > 0 && cols > 0)
	{
		element = new int* [rows];
		for(int r=0; r<rows; r++)
		{
			element[r] = new int [cols];
		}

		for(int r1 = 0; r1 < rows; r1++)
		{
			for(int c = 0; c < cols; c++)
			{
				element[r1][c] = m.element[r1][c];
			}
		}
	}
}



Matrix::~Matrix()
{	
	for(int r1 = 0; r1 < rows; r1++)
	{
		//cout << "delete[] elememt[" << r1 << "];" << endl;		
		delete[] element[r1];
	}
	//cout << "delete[] element;" << endl;	
	delete[] element;
	matrixCount--;
}



Matrix Matrix::operator= (Matrix& m)
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
			for(int c = 0; c < cols; c++)
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
			for(int c = 0; c < cols; c++)
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
			for(int c = 0; c < cols; c++)
				{
					newMatrix[r1][c] = element[r1][c] - m.element[r1][c];
				}
		}
	}
	return newMatrix;
}

Matrix Matrix::multiply(const Matrix& m) const
{
	// r1xc2
	Matrix newMatrix(rows, m.cols); 
 	int R1; 
 	int C1;
	int C2;
	
	for(R1 = 0; R1<rows; R1++) 
 	{
 		for(C1 = 0; C1<m.cols; C1++)
 			{
				for(C2=0; C2<cols; C2++)
 				{	
					newMatrix[R1][C1] += ((element[R1][C2])*(m.element[C2][C1]));
				}

			}
		}
 	return newMatrix;
}

int Matrix::get_matrixCount()
{	
	return matrixCount;
	
}
