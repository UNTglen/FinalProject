/***********************************************************************
  Filename: arrayFunctions.cpp
  Author: Glen Newell
  Description:

  File Modifide: 20061119
	-file created
***********************************************************************/
#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H
#include <iostream>
#include <cmath>
using namespace std;

/***********************************************************************
	Author: Glen Newell
	Function: max
	Description: Finds the largest number in an array
***********************************************************************/
int max (int [], int);

/***********************************************************************
	Author: Glen Newell
	Function: min
	Description: Finds the smallest number in an array
***********************************************************************/
int min (int [], int);

/***********************************************************************
	Author: Glen Newell
	Function: sum
	Description: Calculates the sum of all the numbers in an array
***********************************************************************/
long sum (int [], int);

/***********************************************************************
	Author: Glen Newell
	Function: product
	Description: Calculates the product of all the numbers in an array
***********************************************************************/
long product (int [], int);

/***********************************************************************
	Author: Glen Newell
	Function: selectionSort
	Description: Used to sort and array in accending order
***********************************************************************/
void selectionSort (int [], int);

/***********************************************************************
	Author: Glen Newell
	Function: bubbleSort
	Description: Used to sort and array in accending order
***********************************************************************/
void bubbleSort (int [], int);

/***********************************************************************
	Author: Glen Newell
	Function: linSearch
	Description: Used to serch a sorted array for a value
***********************************************************************/
void linSearch (int [], int, int);

#endif
