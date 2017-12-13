/**************************************************************************
	File name: pointdrivr.cpp
	Author: Glen Newell
	Description: A program to call and test my Point Class

	Date Modifide: 20061030
		-File Created
	Date Modifide: 20061102
		-worked on class structure and driver file.
	Date Modifide: 20061105
		-finished getting project to work on local 
		-cannont find point.h on upload site? 

***************************************************************************/
#include "Point.h"

int main()
{
	string dataFile; //defines input file

	//defines input point files
	double pointX, pointY, pointZ,pointX2, pointY2, pointZ2; 
	
	//ask for a file name and inputes one
	cout << "Enter Filename: ";
	cin >> dataFile;
	
	//opens file
	ifstream inFile;
	inFile.open(dataFile.c_str());
	
	//checks to see if file opens correctly
	if(!inFile)
	{
		cout << "Error loading.";
	}
	else
	
	//inputs corodinates
	inFile >> pointX >> pointY >> pointZ >> pointX2 >> pointY2 >> pointZ2;
	
	//declares corodinates
	XYZPoint p1(pointX, pointY, pointZ);
	XYZPoint p2(pointX2, pointY2, pointZ2);
		
	//uses function to display midpoints
	cout << endl << "Midpoint Coordinates:";
		XYZPoint p3(0,0,0);
		p3.midPoint(p1,p2);
		p3.display(cout);

	//uses function to display the distance
	cout << endl << "The distance is: ";
		double dist = p1.distance(p2);
		cout << dist << endl;
	
	//displays input coordinates (set1)
	cout << endl << "The Coordinates are: ";
		p1.display(cout);

	//displays input coordinates (set2)
	cout << endl << "The Coordinates are: ";
		p2.display(cout);
		cout << endl;

	//clears and closes inFile	
	inFile.clear();
	inFile.close();


//	p2.setXCoor(0);
//	p2.setYCoor(4);

//	p1.display(cout);

//	p1 = p2;

//	p1.setXCoor(p2.getXCoor());
//	p1.setYCoor(p2.getYCoor());
//	p1.setZCoor(p2.getZCoor());
	return 0;
}
