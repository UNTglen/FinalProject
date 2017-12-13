/*********************************************************************
	Filename: GameOfLife.cpp
	Author:	Glen Newell
	Date Created: 20070130
	Date Due:	20070202
	Description: To build the function that will run the GameOfLife
	
	Date Modifide: 20070130
		-File created
	Date Modifide: 20070201
		-after correcting all errors in matrix class finally started
		to assymle the game of life funcionts
		-built GameOfLife Construtor
		-Built the move and print functions withouu values assigned
	DateModifide: 20070202
		-Due today but probably wont finish
		-added comments
		-working on the math to figure out Move funcion
*********************************************************************/

#include "GameOfLife.h"
/*********************************************************************
	Function Name: GameOfLife()
	Author: Glen Newell
	Type: Default Constructor
	Description: Takes a given game of life if no values are assigend
	and assigns random values to build a matrix for the game of life
*********************************************************************/
GameOfLife::GameOfLife()
{
	int value = 1; //sets the alive value
	
	int rowSize = rand()%100; //randomly assigns a matrix row size
	int colSize = rand()%100; //randomly assigns a matrix col size
	Matrix A(rowSize, colSize); // builds a matrix of assigned values

	for(int build = 0;  build < 2; build++)
	{
		int row = rand()%100; //randomly assigns a row
		int col = rand()%100; //randomly assigns a col

		//Sets 3 elements in the matrix to "alive: 1"
		Matrix::setElement(row, col, value); //sets randomly assigned element
		Matrix::setElement((row+1), col, value);//sets randomly assigned element
		Matrix::setElement(row, (col+1), value);//sets randomly assigned element
	}
	
}

/*********************************************************************
	Function Name: GameOfLife(int, int)
	Author: Glen Newell
	Type: Constructor
	Description: Takes a given game of life if values are assigend
	and assigns the values to build a matrix for the game of life
*********************************************************************/
GameOfLife::GameOfLife(int row, int col)
{
	Matrix A(row, col); //builds matrix to specifide values
	int value = 1;//sets the alive value
	for(int build = 0;  build < 2; build++)
	{
		int row = rand()%100;//randomly assigns a row
		int col = rand()%100;//randomly assigns a col
		Matrix::setElement(row, col, value);//sets randomly assigned element
		Matrix::setElement((row+1), col, value);//sets randomly assigned element
		Matrix::setElement(row, (col+1), value);//sets randomly assigned element
	}
}

/*********************************************************************
	Function Name: move()
	Author: Glen Newell
	Type: Move genorator
	Description: takes the values that are in a given matrix and 
	determins if it should become alive, die, or survive. 
*********************************************************************/
 
void GameOfLife::move()
{
	GameOfLife (*this);
}

/*********************************************************************
	Function Name: print()
	Author: Glen Newell
	Type: Move genorator
	Description: print the matrix to the plotter. 
*********************************************************************/
void GameOfLife::print()
{
	draw(*this);
}
