#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class T>
T rend (T data[], T);

int main()
{
	bool run = true;
	string fileName;


	while(run)
	{
		try
		{
			cout << "Please input a file name: ";
			cin >> fileName;

				ifstream inFile;
			inFile.open(fileName.c_str());

			if(!inFile)
			{
				throw "File Not Found. Please Try Again!";
			}

			run = false;

		}

		catch(char * i)
		{
			cout << i << endl << endl;
		}
	}

	
	return 0;
}

template <class T>
T rend (T data[], T)
{
	return reinterpret_cast<char*>(data), 2*sizeof(T);
}