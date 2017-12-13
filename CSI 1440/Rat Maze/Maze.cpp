#include "Maze.h"


Maze::Maze(string inFile)
{
	char ch;
	ifstream in;
	in.open(inFile.c_str());
	if(!in)
	{
		throw "File Not open";
	}

	in >> rows >> cols;
	in >> r.row >> r.col;

	element = new int*[rows];

	for(int r=0; r < rows; r++)
	{
		element[r] = new int[cols];
	}
	
	for(r=0; r < rows; r++)
	{
		for(int c=0; c < cols; c++)
		{
			in >> ch;
			element[r][c] = int (ch-'0');
		}
	}
	
	p.draw(*this);
}
