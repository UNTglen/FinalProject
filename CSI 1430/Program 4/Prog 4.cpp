#include <iostream>
#include <sstream>
using namespace std;
void printReverse(ostream&, char*);

int main()
{

	char *A = "Bobby";

	printReverse(cout,A);

	return 0;
}

void printReverse(ostream& out, char *str)
{
	out << "The string is: ";
	
	int count = 0;

	while(*str)
	{
		out << *str;
		str++;
		count++;
	}

	out << endl << count << endl;
}