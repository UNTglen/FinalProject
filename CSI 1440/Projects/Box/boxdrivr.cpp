/**************************************************************************
	File name:	 Box.h
	Author:		 Glen Newell
	Description: A program that defines my prototypes for "Box.cpp"

	Date Modifide: 20061112
		-File Created

***************************************************************************/

#include "Box.h"

int main()
{
	XYZPoint p1;
	XYZBox b1(1,2,3),
		   b2();

	double SA;
	SA=b1.surfaceArea();

	cout << "Surface Area" << endl << "First Box: " << SA << endl 
		<< "Second Box: " << endl;

	double vol1, vol2;
	vol1=b1.volume();

	cout << "Volume" << endl << "First Box: " << vol1 << endl 
		<< "Second Box: " << endl;

	return 0;
}
