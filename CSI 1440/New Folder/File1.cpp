#include <iostream>
#include <cmath>
using namespace std;

double surfaceArea (double, double, double, double,double, double);

int main()
{
        double SA;
        SA= surfaceArea(8,-2,25,4,16,23);
        cout << SA;

        return 0;
}

double surfaceArea (double x1, double x2, double y1, double y2, double z1, double z2)
        {
	   double depth = abs(x1 - x2);
	   double width = abs(y1 - y2);
	   double height = abs(z1 - z2);

	   double result = abs((2*(depth*width))+(2*(depth*height))+(2*(width*height)));
	   return result;
	}