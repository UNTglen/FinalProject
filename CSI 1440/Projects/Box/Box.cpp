/**************************************************************************
	File name:	 Box.h
	Author:		 Glen Newell
	Description: A program that defines my prototypes for "Box.cpp"

	Date Modifide: 20061106
		-File Created
	Date Modifide: 20061110
		-Comments Added
		-Added large & Small dimension calls
	Date Modifide: 20061112
		-Worked on Volume function
		-worked on larg and Small dimension functions
		-worked on get_Coor & set_Coor Functions

***************************************************************************/
#include "Box.h"


	XYZBox::XYZBox (XYZPoint p1, XYZPoint p2, XYZPoint p3)
	{
		xCoor = p1;
		yCoor = p2;
		zCoor = p3;
	}

	XYZBox::XYZBox (double x, double y, double z)
	{		

		xCoor.setXCoor(0);
		xCoor.setYCoor(0);
		xCoor.setZCoor(x);

		yCoor.setXCoor(0);
		yCoor.setYCoor(y);
		yCoor.setZCoor(0);

		zCoor.setXCoor(z);
		zCoor.setYCoor(0);
		zCoor.setZCoor(0);
	}


/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: get(X,Y,Z)Coor
*
*	Discription: 
*		Prototype get*Coor that passes an X,Y, or Z Coordinate
*
***************************************************************************/
	
	XYZPoin XYZBox::getXCoor() //depth
	{	
		return xCoor;
	}

	double XYZBox::getYCoor(double yCoor) //width
	{
		return yCoor;
	}

	double XYZBox::getZCoor(double zCoor) //height
	{
		return zCoor;
	}

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: set(X,Y,Z)Coor
*
*	Discription: 
*		Prototype set*Coor that passes an X,Y, or Z Coordinate
*
***************************************************************************/
	void XYZBox::setXCoor(double xCoor)
	{
		xCoor = xCoor;
	}

	void XYZBox::setYCoor(double yCoor)
	{
		yCoor = yCoor;
	}

	void XYZBox::setZCoor(double zCoor)
	{
		zCoor = zCoor;
	}

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: distance
*
*	Discription: 
*		Calculates the difference in between the xCoor with 
*
***************************************************************************/
	double XYZBox::surfaceArea()
	{
	   double depth = abs(xCoor.getXCoor() - yCoor.getXCoor());
	   double width = abs(yCoor.getYCoor() - zCoor.getYCoor());
	   double height = abs(zCoor.getZCoor() - xCoor.getZCoor());

	   double result = abs((2*(depth*width))+(2*(depth*height))+(2*(width*height)));
	   return result;
	}

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: volume
*
*	Discription: 
*		Calculates the volume of the Box. 
*
***************************************************************************/
	double XYZBox::volume()
	{
		double volume = xCoor.getXCoor()*
			yCoor.getYCoor()*zCoor.getZCoor();
		return volume;
	}

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox
*	Function: largeDimension
*	
*	Discription: 
*		calculates the Largest Dimension of the box
***************************************************************************/
//	void XYZBox::largeDimension (XYZBox p1, XYZBox p2);
//	{
//	}

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox
*	Function: smallDimension
*	
*	Discription: 
*		calculates the Smallest Dimension of the box
***************************************************************************/
//	void smallDimension (XYZBox, XYZBox);
//	{
//	}

