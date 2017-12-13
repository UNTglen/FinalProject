/**************************************************************************
	File name: point.h
	Author: Glen Newell
	Description: A program that defines my prototypes for "point.cpp"

	Date Modifide: 20061030
		-File Created
	Date Modifide: 20061102
		-worked on class structure and driver file.	
	Date Modifide: 20061105
		-finished getting project to work on local 
		-cannont find point.h on upload site? 

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
*
*		class: XYZPoint
*		
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
		XYZPoint() //default constructor, sets default to 0.0
		{
			xCoor = 0.000;
			yCoor = 0.000;
			zCoor = 0.000;
		}

	//prototype Constructor passing three doubles
	XYZPoint(double, double, double);

	//prototype to get X,Y, & Z coordinates
	double getXCoor(double);
	double getYCoor(double);
	double getZCoor(double);

	//prototype to set x,y & z coordinates
	void setXCoor(double);
	void setYCoor(double);
	void setZCoor(double);

	//prototype for distance funciton
	double distance(XYZPoint);

	//prototype for midpoint function
	void midPoint(XYZPoint, XYZPoint);
	//void midPoint(XYZPoint, XYZPoint, XYZPoint);
	
	//prototype for display function
	void display(ostream &);

};
#endif
