#include "arrayFunctions.h"

int main()
{
	int value, i=25;
	int array[] ={2,3,7,9,11,13,20,20,21,29,33,39,42,45,50,50,52,56,57,63,67,67,67,68,68};
	value = max (array, i);
	cout << "Minimum value is: " << value << endl;

	value = min (array, i);
	cout << "Minimum value is: "<< value << endl;

	value = sum(array, i);
	cout << "The Sum of the array is: " << value << endl;

	value = product(array, i);
	cout << "The product of the array is: " << value << endl;

//	bubbleSort(array,i);

//	for(int j= 0; j <= (i-1); j++)
//	{
//		cout << array[j] << "\t";
//	}

	selectionSort(array,i);

	for(int u= 0; u <= (i-1); u++)
	{
		cout << array[u] << "\t";
	}


	cout << endl;
}