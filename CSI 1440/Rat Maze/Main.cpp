#include "Maze.h"
//#include <iostream>
//#include <fstream>

using namespace std;

int main()
{
	/*char ch;
	ifstream inFile;
	inFile.open("maze.txt");

	if(!inFile)
	{
		cout << "bad file";
		return 0;
	}

	while(inFile)
	{
		inFile >> ch;
		cout << ch;
	}
*/
	try
	{
		Maze m("maze.txt");
		//m.run();
		return 0;
	}

	catch(string i)
	{
		cout << i;
	}
	return 0; 
}

