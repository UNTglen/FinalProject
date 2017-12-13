/************************************************************************************
	File name: point.cpp
	Author: Glen Newell
	Description: A program that defines my point class "point.h"

	Date Modifide: 20061030
		-File Created
	Date Modifide: 20061102
		-worked on class structure and driver file.

*************************************************************************************/

#include "point.h"

	//prototype Constructor passing two doubles
	XYZPoint::XYZPoint(double x, double y, double z)
	{
		xCoor = x;
		yCoor = y;
		zCoor = z;

		cout << "In Constructor with two doubles" << endl;
		cout << fixed << setprecision(3) << xCoor << " " << yCoor 
			<< " " << zCoor << endl;
		cout << x << " " << y << " " << z << endl;
	}

/************************************************************************************
*
*	class XYZ Accessors
*
*************************************************************************************/
	double XYZPoint::getXCoor(double x)
	{
		return xCoor;
	}

	double XYZPoint::getYCoor(double y)
	{
		return yCoor;
	}

	double XYZPoint::getZCoor(double z)
	{
		return zCoor;
	}

/************************************************************************************
*
*	class XYZ 
*	Modifiers
*
*************************************************************************************/
	void XYZPoint::setXCoor(double x)
	{
		xCoor = x;
	}

	void XYZPoint::setYCoor(double y)
	{
		yCoor = y;
	}

	void XYZPoint::setZCoor(double z)
	{
		zCoor = z;
	}

/************************************************************************************
*
*	class: XYZPoint 
*	Function distance
*	calculates the difference in between the xCoor with 
*
*************************************************************************************/
	double XYZPoint::distance(XYZPoint p1)
	{
		double xDiff = xCoor - p1.getXCoor(xCoor);
		double yDiff = yCoor - p1.getYCoor(yCoor);
		double zDiff = zCoor - p1.getZCoor(zCoor);
		//double xDiff = xCoor - p1.getXCoor();
		//double yDiff = yCoor - p1.getYCoor();
		//double zDiff = zCoor - p1.getZCoor();
		
		double result = sqrt(xDiff*xDiff + yDiff*yDiff + zDiff*zDiff);
		return result;
	}

/************************************************************************************
*
*	class: XYZPoint 
*	Function: midPoint
*	
*	Function Description: finds the midpoint of the X,Y & Z Corrodinates
*
*************************************************************************************/
	void XYZPoint::midPoint(XYZPoint p2, XYZPoint p3, XYZPoint p4) //p3.midpoint(p1.p2);
	{
		//xCoor = (p2.xCoor() + p3.xCoor() + p4.xCoor())/2.0;
		//yCoor = (p2.yCoor() + p3.yCoor() + p4.yCoor())/2.0;
		//zCoor = (p2.zCoor() + p3.zCoor() + p4.zCoor())/2.0;
		xCoor = (p2.getXCoor(xCoor) + p3.getXCoor(xCoor) + p4.getZCoor(xCoor))/2.0;
		yCoor = (p2.getYCoor(yCoor) + p3.getYCoor(yCoor) + p4.getYCoor(yCoor))/2.0;
		zCoor = (p2.getZCoor(zCoor) + p3.getZCoor(zCoor) + p4.getZCoor(zCoor))/2.0;
	}

/************************************************************************************
*
*	class: XYZPoint 
*	Function: Display
*	
*	Funciont Description: displays the 
*
*************************************************************************************/
	void XYZPoint::display( ostream &) //p3.display (cout)
	{
		
		cout << fixed << setprecision(8) << "(" << xCoor << "," 
			<< yCoor << "," << zCoor <<")";
	}
