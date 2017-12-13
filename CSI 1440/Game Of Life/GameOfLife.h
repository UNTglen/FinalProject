/*********************************************************************
	Filename: GameOfLife.h
	Author:	Glen Newell
	Date Created: 20070130
	Date Due:	20070202
	Description: To build the prototypes that will run the GameOfLife
	
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

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include "Plotter.h"

class GameOfLife:public Matrix //inherits the Matrix class
{
private:
	Plotter screen; //Defines a Polletr named Screen
public:
	GameOfLife(); //Default constructor no values
	GameOfLife(int row,int col); //Constructor with values
	void move(); //Prototype for the move Function
	void print();//Prototype for the print Function

};

#endif
