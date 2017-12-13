#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	bool run = true;
	char ch;
	//int x;
	string fileName;

/*
	while(run)
	{
		try
		{
			cout << "Please input a file name: ";
			cin >> fileName;

			ofstream outFile;
			outFile.open(fileName.c_str(),ios::binary | ios::out);

			if(!outFile)
			{
				throw "Unable to creat file. Please Try Again!";
			}

			run = false;

			double d[2] = {12.3 , 34.5};
			outFile.write(reinterpret_cast<char*>(d), sizeof (d));

		}

		catch(char * i)
		{
			cout << i << endl << endl;
		}
*/
		try
		{
			cout << "Please input a file name: ";
			cin >> fileName;

			ifstream inFile;
			inFile.open(fileName.c_str(),ios::binary | ios::in);

			if(!inFile)
			{
				throw "Unable to find file. Please Try Again!";
			}

			run = false;

			int data[10];
			inFile.read(reinterpret_cast<char*>(data), 2*sizeof (int));

			while(inFile >> ch)
			{
				cout << ch;
			}

		}

		catch(char * i)
		{
			cout << i << endl << endl;
		}
//	}

	

	
	return 0;
}

	//return reinterpret_cast<char*>(data), 2*sizeof(T);