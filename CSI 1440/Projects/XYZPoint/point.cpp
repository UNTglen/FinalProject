/************************************************************
	Filename:		point.cpp
	Author:			Glen Newell
	Description: 

	File Modifide:  20061102
			-File created
************************************************************/

#include "point.h"


//prototype Constructor passing two doubles
XYZPoint::XYZPoint(double x, double y, double z)
	{
		xCoor = x;
		yCoor = y;
		zCoor = z;
		cout << "In Constructor with two doubles" << endl;
	}
/*		
	//Accessors
	double XYPoint::getXCoor(double x)
		{
			return xCoor;
		}

	double XYPoint::getYCoor(double y)
		{
			return yCoor;
		}

	//Modifiers
	void XYPoint::setXCoor(double x)
		{
			xCoor = x;
		}

	void XYPoint::setYCoor(double y)
	{
		yCoor =y;
	}

	double XYPoint::distance(XYPoint p)
	{
		
		double xDiff = xCoor - p.getXCoor(xCoor);
		double yDiff = yCoor - p.getYCoor(yCoor);
		
		double result = sqrt( xDiff*xDiff +yDiff*yDiff);
	}

	void XYPoint::midPoint(XYPoint p1, XYPoint p2) //p3.midpoint(p1.p2);
	{
		xCoor = (p1.getXCoor(xCoor) + p2.getXCoor(xCoor))/2.0;
		yCoor = (p1.getYCoor(yCoor) + p2.getYCoor(yCoor))/2.0;
	}

	void XYPoint::display(ostream&) //chance p3.display (cout)
	{
		cout << "(" << xCoor "," << yCoor << ")";
	}

  */