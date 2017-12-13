/************************************************************
	Filename: point.h
	Author:
	Description:

	File Modifide: 20061102
			-File created
************************************************************/

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class XYZPoint
{
	private: //declares Coorodinates
		double xCoor;
		double yCoor;
		double zCoor;

	public:
		XYZPoint() //default constructor
		{
			xCoor = 0.0;
			yCoor = 0.0;
			zCoor = 0.0;
		}

		//prototype Constructor passing three doubles
		XYZPoint(double, double, double);
		
		//Accessors
		double getXCoor(double);
		double getYCoor(double);
		double getZCoor(double);

		//Modifiers
		void setXCoor(double);
		void setYCoor(double);
		void setZCoor(double);

		/*double distance(XYZPoint);

		void midPoint(XYZPoint, XYZPoint);

		void display(ostream &);*/
};



















double distance(double x, double y);


#endif