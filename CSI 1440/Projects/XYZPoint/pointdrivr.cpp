/************************************************************
	Filename: pointdrivr.cpp
	Author:
	Description:

	File Modifide: 20061102
			-File created
************************************************************/

#include "point.h"

int main()
{
	string dataFile;
	double pointX, pointY, pointZ;
	cout << "Enter Filename: ";
	cin >> dataFile;
	
	ifstream inFile;
	inFile.open(dataFile.c_str());

	if(!inFile)
	{
		cout << "Error loading.";
	}
	else
		
	inFile >> pointX >> pointY;
	cout << "Point 1 is: " << pointX << endl;
	cout << "Point 2 is: " << pointY << endl;

	pointZ=distance(pointX, pointY);
	cout << "point 3 is: " << pointZ << endl;

	return 0;
}