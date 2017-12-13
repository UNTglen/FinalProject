#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <cmath>
using namespace std;

class XYPoint
{
	private:
		double xCoor;
		double yCoor;
	public:
		XYpoint() //default constructor
		{
			xCoor = 0.0;
			yCoor = 0.0;

			cout << "In Default Constructor" << endl;//dont ever do this!
		}

		//prototype Constructor passing two doubles
		XYPoint(double, double)
		
		//Accessors
		double getXCoor(double);
		double getYCoor(double);

		//Modifiers
		void setXCoor(double);
		void setYCoor(double);

		double distance(XYPoint);

		void midPoint(XYPoint, XYPoint); //p1.midpoint(p2.p3);

		void display(ostream &);//refer to 1

};

//1 void display ( ostream & XYPoint);

//XYpoint midPoint( XYPoint, XYPpoint);

#endif