/***********************************************************************
  Filename: arrayFunctions.cpp
  Author: Glen Newell
  Description:

  File Modifide: 20061119
	-file created
***********************************************************************/
#include "arrayFunctions.h"

/***********************************************************************
	Author: Glen Newell
	Function: max
	Description: Finds the largest number in an array
***********************************************************************/
int max (int list[], int size)
{
	int maximum = list[0];

	for (int i=1; i < size; i++)
	{
		if(list[i] > maximum)
		{
			maximum =list[i];
		}
	}
	return maximum;
}

/***********************************************************************
	Author: Glen Newell
	Function: min
	Description: Finds the smallest number in an array
***********************************************************************/
int min (int list[], int size)
{
	int minimum = list[0];

	for (int i=1; i < size; i++)
	{
		if(list[i] < minimum)
		{
			minimum =list[i];
		}
	}
	return minimum;
}

/***********************************************************************
	Author: Glen Newell
	Function: sum
	Description: Calculates the sum of all the numbers in an array
***********************************************************************/
long sum (int list[], int size)
{
	long temp = list [0];

	for (int i=1; i < size; i++)
	{
		temp= temp + list[i];
	}

	return temp;
}

/***********************************************************************
	Author: Glen Newell
	Function: product
	Description: Calculates the product of all the numbers in an array
***********************************************************************/
long product (int list[], int size)
{
	long temp = list [0];

	for (int i=1; i < size; i++)
	{
		temp= temp * list[i];
	}

	return temp;
}

/***********************************************************************
	Author: Glen Newell
	Function: selectionSort
	Description: Used to sort and array in accending order
***********************************************************************/
void selectionSort (int list[], int size)
{
	int temp, x=0; 

	for(int i=(size - 1); i >= 0; i--) 
	{
		for(int j=1; j <= i; j++)
		{
			if(list[j] < list[x])
			{
				x=j;
			}
			temp= list[x];
			list[x]=list[i];
			list[i]=temp;
		}

	}
}
/***********************************************************************
	Author: Glen Newell
	Function: bubbleSort
	Description: Used to sort and array in accending order
***********************************************************************/
void bubbleSort (int list [], int size)
{
	int temp; //used for actuall swapping process

// i = offset of size, i greater than zero, countdown of i;
	for(int i=(size - 1); i >= 0; i--) 
	{
		//j=1, j <= the offset, j+1
		for(int j=1; j <= i; j++)
		{
			//if the offset of j is greater than list of j. 
			if(list[j-1] > list[j])
			{
				temp = list[j-1]; // temp becomes j-1
				list[j-1]=list[j]; // list becomes j-1
				list[j]=temp; // list j becomes j-1
			}
		}
	}
}

/***********************************************************************
***********************************************************************/
void linSearch (int list[], int size, int item)
{
	bool found = false;
	int position =-1;

	for(int index = 0; ((index < size) && (!found)); index++)
	{
		if(list[index]==item)
		{
			position = index;
			found = true;
		}
	}
}


