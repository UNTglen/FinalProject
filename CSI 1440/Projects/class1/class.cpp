#include "class.h"

//prototype Constructor passing two doubles
	XYPoint( double x, double y )
		{
			xCoor = x;
			yCoor = y;

			cout << "In Constructor with two doubles" << endl;
		}
		
	//Accessors
	double getXCoor()
		{
			return xCoor;
		}

	double getYCoor()
		{
			return yCoor;
		}

	//Modifiers
	void setXCoor::( double x )
		{
			xCoor = x;
		}

	void setYCoo::( double y )
	{
		yCoor =y;
	}

	double distance( XYPoint p)
	{
		double xDiff = xCoor - p.getXCoor();
		double yDiff = yCoor - p.getYCoor();
		
		double result = sqrt( xDiff*xDiff +yDiff*yDiff);
	}

	void midPoint::( XYPoint p1, XYPoint p2 ); //p3.midpoint(p1.p2);
	{
		xCoor = ( p1.getXCoor() + p2.getXcoor() )/2.0;
		yCoor = ( p1.getYCoor() + p2.getYcoor() )/2.0;
	}

	void display::( ostream & chance) //p3.display (cout)
	{
		cout << "(" << xCoor "," << yCoor << ")";
	}