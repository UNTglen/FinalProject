#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main ()
{	
	
	// creats pateren
	// *
	// **
	// ***
	// ****
	// *****
	for(int i = 5; i > 0; i--)
	{
		for(int n = 0; n<i; n++)
		{
			cout << "*";
		}
	cout << endl;
	}
	
	// creats pateren
	// *****
	// ****
	// ***
	// **
	// *

	for(int a=0; a<5; a++)
	{
		for(int b=0; b<=a; b++)
		{
			cout << "*";
		}
	cout << endl;
	}
	
	// creats pateren
	// *****
	//  ****
	//   ***
	//    **
	//     *
	for(int c=0; c<5; c++)
	{
		for(int d=0; d<c; d++)
		{
			cout << " ";

				for(int e=5; e>=c; e--)
				{
					cout << "*";	
				}
			
		}
		cout << endl;
	}

	// creats pateren
	//     *
	//    **
	//   ***
	//  ****
	// *****
	for(int f=0; f<5; f++)
	{
		for(int g=4; g>f; g--)
		{
			cout << " ";

			for(int h=0; h<=f; h++)
				{
					cout << "*";	
				}
		cout << endl;	
		}
		
	}






return 0;

}




/*	bool flag = true;
	ifstream infile;
	string filename = "numbers.dat";
	int value;

	while( flag )
	{	
		infile.open(filename.c_str());
		while(infile >> value)
	{
		cout << value << endl;
		}

		cout << "Enter a new filename: ";
		cin >> filename;

		cout << filename << endl;

		if(filename == "n")
		{
			flag = false;
		}
		infile.close();
		infile.clear();
		*/
