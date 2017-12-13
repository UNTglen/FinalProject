#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("Maze.txt");

	if(!inFile)
	{
		cout << "wrong file name";
		return 0;
	}

	while(inFile)
	{
		cout << inFile;
	}
	return 0;
}
