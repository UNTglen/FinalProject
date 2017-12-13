/**************************************************************************
	File name: Point.h
	Author: Glen Newell
	Description: A program that defines my prototypes for "point.cpp"

	Date Modifide: 20061030
		-File Created
	Date Modifide: 20061102
		-worked on class structure and driver file.	
	Date Modifide: 20061105
		-finished getting project to work on local 
		-cannont find point.h on upload site? 
	Date Modifide: 20061110
		-Comments Added Correctly

***************************************************************************/
#ifndef POINT_H 
#define POINT_H
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

/**************************************************************************
*	Author: Glen Newell
*	class:  XYZPoint
*		
*	Description: 
*		A constructor that passes 3 variables
*		A default constructor that has preset values
*		A function for setting the x,y and z variables
*		A function to compute the distance between the two points
*		A function to compute the midpoint between the two points
*		A function that will display all the points attributes
*		Sperate accessor functions fro getting each attribute. 
*
***************************************************************************/

class XYZPoint
{
	//constructor that passes 3 veriables
	private: //declares Coorodinates
		double xCoor;
		double yCoor;
		double zCoor;

	public:
/**************************************************************************
*	Author: Glen Newell
*	Class: XYZPoint 
*	Function: XYZPoint
*
*	Discription: 
*		Default Constructor that sets the x,y & z Coor to 0.00 if no value
*		is passed.
***************************************************************************/
		XYZPoint()
		{
			xCoor = 0.000;
			yCoor = 0.000;
			zCoor = 0.000;
		}

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZPoint
*	Function: XYZPoint
*
*	Discription: 
*		Prototype Constructor that passes three doubles, defines the points
*		of the triangle
***************************************************************************/
	XYZPoint(double, double, double);

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZPoint 
*	Function: get(X,Y,Z)Coor
*
*	Discription: 
*		Prototype get*Coor that passes an X,Y, or Z Coordinate
***************************************************************************/
	double getXCoor();
	double getYCoor();
	double getZCoor();

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZPoint 
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
*	Class: XYZPoint 
*	Function: distance
*	
*	Discription: 
*		calculates the distance between coordinates of XYZPoint
***************************************************************************/
	double distance(XYZPoint);

/**************************************************************************
*	Author: Glen Newell
*	Class: XYZPoint
*	Function: midPoint
*	
*	Discription: 
*		calculates the midpoint between coordinates of XYZPoint
***************************************************************************/
	void midPoint(XYZPoint, XYZPoint);
	
/**************************************************************************
*	Author: Glen Newell
*	Class: XYZPoint
*	Function: Display
*	
*	Discription: 
*		Allows user to output to anywhere or anything
***************************************************************************/
	void display(ostream &);

};
#endif
