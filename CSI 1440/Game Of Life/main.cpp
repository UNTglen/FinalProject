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

int main()
{
	GameOfLife g;
	while(true)
	{
		g.print();
		g.move();
	}

	return 0;
}
