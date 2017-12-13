/***************************************************************
  File name:		SAD.cpp
  Author:			Glen Newell
  Discription:		To be able to input 4 intagers and caculate 
					the Sum, Average, and Standard Devation of 
					them. Also to display the results.

  File Modifide:	20060829
		-File Created

  File Modifide:	20060831
		-Redeclared double's and created int's x1 x2 x3 x4

  File Modifide 20060901
		-Changed standered deviation equation
***************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
		int x1, x2, x3, x4; //declares intagers

		double sum, avg, stdev; //declares sum, avg and stdev


	cout << "Input 4 intagers (ie: 1 2 3 4):";
		cin >> x1 >> x2  >> x3 >> x4;
	cout << "Your 4 intagers are:" << x1 << " " <<x2 << " " <<x3 << " " <<x4 << endl;

		sum=x1+x2+x3+x4; //caculates the sum of the intagers
			cout << "The sum of your intagers is:" << sum << endl;

		avg=sum/4.0; //caculates the average of the intagers
			cout << "The average of your intagers is:" << avg <<endl;

		stdev=sqrt((pow((x1-avg),2)+pow((x2-avg),2)+pow((x3-avg),2)+pow((x4-avg),2))/4.0); 
		//caculates the standard devation of the intager
			cout << "The standard deveation of your intagers is:" << stdev << endl;
		return 0;
}

