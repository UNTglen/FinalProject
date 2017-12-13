/**************************************************************************
	File name:	 Box.h
	Author:		 Glen Newell
	Description: A program that defines my prototypes for "Box.cpp"

	Date Modifide: 20061106
		-File Created
	Date Modifide: 20061110
		-Comments Added
		-Added large & Small dimension prototypes

***************************************************************************/
#ifndef BOX_H
#define BOX_H
#include "Point.h"

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox
*		
*	Description:
*		A constructor for 3 points that define the box *
*		A constructor with arguments for hight, width and depth *
*		A function to compute the surface area of the box
*		A function to compute the volume 
*		Sperate accessor functions fro getting each attribute. 
*		Separate functions that will return the demensions of the box
*		A function that will return the largest dimension of the box
*		A function that will return the smallest dimension of the box
*	
***************************************************************************/

class XYZBox
{
	//constructor that defines the 3 points of the box
	private: //declares Coorodinates
		XYZPoint xCoor;
		XYZPoint yCoor;
		XYZPoint zCoor;

	public:
/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: XYZBox
*
*	Discription: 
*		Prototype Constructor that passes three doubles, defines Box(H,W,D)
***************************************************************************/
	XYZBox(double, double, double);
	XYZBox(XYZPoint, XYZPoint, XYZPoint);

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: get(X,Y,Z)Coor
*
*	Discription: 
*		Prototype get*Coor that passes an X,Y, or Z Coordinate
***************************************************************************/
	double getXCoor(double);
	double getYCoor(double);
	double getZCoor(double); 
/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: set(X,Y,Z)Coor
*
*	Discription: 
*		Prototype set*Coor that passes an X,Y, or Z Coordinate
***************************************************************************/
	void setXCoor(double);
	void setYCoor(double);
	void setZCoor(double);

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox 
*	Function: surfaceArea
*	
*	Discription: 
*		calculates the difference in between the xCoor with 
***************************************************************************/
	double surfaceArea();

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox
*	Function: Volume
*	
*	Discription: 
*		calculates the volume of the box
***************************************************************************/
	double volume();
	
/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox
*	Function: largeDimension
*	
*	Discription: 
*		calculates the Largest Dimension of the box
***************************************************************************/
	void largeDimension (XYZBox, XYZBox);

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZBox
*	Function: smallDimension
*	
*	Discription: 
*		calculates the Smallest Dimension of the box
***************************************************************************/
	void smallDimension (XYZBox, XYZBox);


};

#endif
