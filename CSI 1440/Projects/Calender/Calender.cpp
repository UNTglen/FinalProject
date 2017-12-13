/************************************************************

  File Name:	Calender.cpp	
  Author:		Glen Newell
  Desription:	To help the clergy keep track of there color
				and calender date for the curch. 

  File Modified: 20060911
		-File Created
		
  File Modified: 20060915
		-change structure format from a lot of netsed 
		 "if" statmenents to a math function of multipling
		 day times month. 

  File Modified  20060926
		-finished structure and edited it to make it compile
************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//Deifnes Day, Month and Year.
	int month, day, year;

	//ask's for and stores Day, Month and Year.
	cout << "Enter the Month: ";
		cin >> month;
	cout << "Enter the Day: ";
		cin >> day;
	cout << "Enter the Year: ";
		cin >> year;

	//defines Advent
	if ((month == 11 && day >= 27 && day <=30 && year == 2005) 
		|| (month == 12 && day >= 1 && day <=24 && year == 2005))
		{
		cout << "Blue, Advant, " << "" << month<< " " << day << ", " 
			<< year;
		return 0;	
	}

	//defines Christmas
	if ((month == 12 && day >= 25 && day <=31 && year == 2005) 
		|| (month == 1 && day >= 1 && day <=14 && year == 2006))
		{
		cout << "White, Christmas, " << "" << month<< " " << day << ", "
			<< year;
		return 0;	
	}

	//defines Epiphany
	if ((month == 1 && day >= 15 && day <=31 && year == 2006) 
		|| (month == 2 && day >= 1 && day <=29 && year == 2006)
		|| (month == 3 && day <= 4 && year == 2006))
		{
		cout << "Green, Epiphany, " << "" << month<< " " << day << ", "
			<< year;
		return 0;	
	}

	//defines Lent
	if ((month == 3 && day >= 6 && day <=31 && year == 2006) 
		|| (month == 4 && day >= 1 && day <=15 && year == 2006))
		{
		cout << "Purple, Lent, " << "" << month<< " " << day << ", "
			<< year;
		return 0;	
	}

	//defines Easter
	if ((month == 4 && day >= 16 && day <=31 && year == 2006) 
		|| (month == 5 && day <=31 && year == 2006)
		|| (month == 6 && day <=3 && year == 2006))
		{
		cout << "Gold, Easter, " << "" << month<< " " << day << ", "
			<< year;
		return 0;	
	}

	//defines Pentecost
	if ((month == 6 && day >= 4 && day <=31 && year == 2006) 
		|| (month == 7 && day <=31 && year == 2006)
		|| (month == 8 && day <=31 && year == 2006)
		|| (month == 9 && day <=31 && year == 2006)
		|| (month == 10 && day <=31 && year == 2006)
		|| (month == 11 && day <=31 && year == 2006)
		|| (month == 12 && day <=31 && year == 2006))
		{
		cout << "Red, Pentecost, " << "" << month<< " " << day << ", "
			<< year;
		return 0;	
	}

	//defines invalid statment if anything else is types
	else
		cout << "invalid statment";
	return 0;
}
