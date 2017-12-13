#include <iostream>
using namespace std;

char genSequence( int round ); //prototype

int main() //test type
{
	for(int i=0; i < 10; i++)
	{
		for(int j=0; j < i; j++)
		{
			cout << genSequence(i);
		}
		cout << endl;
	}
	return 0;
}

char genSequence ( int round ) //definition
{
	static int counter;
	char result;
	int	temp;

	if(counter==0)
	{
		srand(5); //seats the random with 5
	}
	
	//if my random number is a multiple of 4 returns to 0
	temp = rand() % 4; 
	

	switch(temp)
	{
		case 0:
				result = 'r';
				break;
		case 1:
				result = 'b';
				break;
		case 2:
				result = 'y';
				break;
		case 3:
				result = 'g';
	}
	
	counter++;
//if my counter is eqaul to the round im in, it will reset the counter to 0
	if(counter == round) 
	{
		counter =0;
	}
	
	return result;

}