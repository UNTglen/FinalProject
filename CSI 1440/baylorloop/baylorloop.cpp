#include <iostream>
using namespace std;

double Abs(double Nbr)
{
	if( Nbr >= 0 )
		return Nbr;
	else
		return -Nbr;
}

double SquareRoot(double a)
{
	double b = a / 2;
	const double guess = 2;

	do b = (b + a / b) / 2;
	while( Abs(b * b - a) > guess);

	return b;
}

int main()
{
	double b = 25;
	double a    = SquareRoot(b);

	cout << "The square root of " << Number << " is " << a << "\n\n";

	return 0;
}











































/*#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{


	char c, d, keyword[7]; 
	

	ifstream inFile;
	ifstream infile;
	ofstream outFile;
	
	cout << "input keyword: ";
	cin.width(7);	
	cin >> keyword;

	outFile.open("infile.txt");
	
	if(!outFile)
	{
		cout << "error!";
		return 0;
	}

	outFile << keyword;
	outFile.clear();
	outFile.close();

	outFile.open("output.txt");
	inFile.open("input.txt");
	infile.open("infile.txt");

	if(inFile.get(c))
	{ 
		cout << c;
		if(infile.get(d))
			{
				cout << d;	
			}
		outFile << static_cast<char>(c) + static_cast<char>(d);
	}

return 0;
}
*/