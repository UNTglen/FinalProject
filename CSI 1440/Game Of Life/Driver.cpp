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