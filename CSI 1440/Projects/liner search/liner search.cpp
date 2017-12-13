#include <iostream>
using namespace std;

int linerSearch(int list [], int size, int value);
void bubbleSort (int list [], int size);

int main()
{
	return 0;
}

int linerSearch(int list [], int size, int value)
{
	bool = false;
	int position =-1;

	for(int index = 0; ((index < size) && (!found)); index++)
	{
		if(list[index]==value)
		{
			position = index;
			found = true;
		}
	}
	return position;
}



void bubbleSort (int list [], int size)
{
	int temp; //used for actuall swapping process

	for(int i=0; i < size; i ++)
	{
		for(int j=0; j < size; j++)
		{
			if(list[j] > list[j+1])
			{
				temp = list[j];
				list[j]=list[j+1];
				list[j+1]=list[j];
			}
		}
	}

}