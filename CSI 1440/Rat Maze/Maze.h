#ifndef MAZE_H
#define MAZE_H
#include "Matrix.h"
#include <string>
#include "Plotter.h"
#include <fstream>
#include "Rat.h"

class Maze : public Matrix
{
private:
	Plotter p;
	Rat r;
public:
	Maze(string);
	void run();
	bool move(int, int);
};

#endif