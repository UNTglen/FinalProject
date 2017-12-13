/**************************************************************
  File Name:	myFunctions.cpp
  Authour:	Glen Newell
  Descriprion:	To creat my own funtions.

  File Modifide: 20061009
		-File Created
		-maximum funtions completed
		-minimum functinos completed
  File Modifide: 20061010
		-absolute funtions completed
  File Modifide: 20061014
		-added rest of the funcitons
  File Modifide: 20061016
		-working on getting functions to caculate correctly
**************************************************************/
#include "myFunctions.h"

//Defines Function maximum
int maximum(int a, int b)
{
	int result;
	
	if(a>b) //if a is less than b return a
	{
		result=a;
	}

	else if (a<b) //if b is less than a return b
		{
			result=b;
		}

	else if (a=b)
	{
		result=b;
	}
	return result;
}

//defines Function maximum 
double maximum(double a, double b)
{
	double result;
		if(a>b) //if a is less than b return a
	{
		result=a;
	}

	else if (a<b) //if b is less than a return b
		{
			result=b;
		}

	else if (a=b)
	{
		result=b;
	}
	return result;
}
//Defines Function minimum
int minimum(int g, int h)
{
	int result;
	if(g>h)//if g is greater than h than return h
	{
		result=h;
	}

	else if (h>g)//if h is greater than g than return g
	{
		result=g;
	}

	else if (h=g)//if g is equal to h than return h
	{
		result=h;
	}
	return result;
}

//defines Function maximum 
double minimum(double i, double j)
{
	double results;
	if(i>j)//if i is greater than j than return j
	{
		results=j;
	}
		else if (j>i)//if j is greater than i return i
		{
			results=i;
		}

	else if (i=j)//if i is equal to j return i
	{
		results=i;
	}
	return results;
}

//defines Function absolute
int absolute(int a)
{
	int result;
	if (a <= 0)
	{ 
		result=a*(-1); //multiplies a times -1 to give value
	}
		else if(a > 0)
		{ 
			result=a;	
		}
	return result;
}

//defines Function absolute
double absolute(double a)
{
	double result;
	if (a <= 0)
	{ 
		result=a*(-1);//multiplies a times -1 to give value
	}
		else if(a > 0)
		{ 
			result=a;	
		}
	return result;
}

//defines Function power
double power ( double a, int b)
{
	double result, c, d;
	c=2;
	d = a;

	if(b <=0) //if power is negative returns given number
	{
		result=b;
		return result;
	}

	while(c <= b) //caculates power
	{
		d= a*d;
		c++;
	}

	result = d;
	return result;
}

//defines Function squareRoot
double squareRoot( double a)
{
	double result,b,c ; //defines result and b
	double g=(a/2);
	const double guess=(g+g/a)/2;  //guess number
	double closeness = .001;
	if(a <= 0)
	{
		result=a; //if a is a negagtive or zero returns a
		return result;
	}
	
	c=0;//counter
	b=guess;
	while(c<=25) //loops 25 times
	{	// defines how close you need to be
		
		if(absolute((guess*guess)-a) < closeness)  
		{
			b=guess;
			return b;
		}
			b =((a/b)+b)/2; //newtons method
			c++;
		
	}
	result=b;
	return result;
}

//defines Function hypotenuse
double hypotenuse (double a, double b)
{	
	double result, c;

	c=squareRoot((a*a)+(b*b)); //caculates hypotenuse

	result=c;
	return result;
}
