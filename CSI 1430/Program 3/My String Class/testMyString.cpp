#include <iostream>
#include <sstream>
#include "myString.hpp"

using namespace std;

void testConstructor(ostream&);
void testConstructor2(ostream&); 
int main()
{
	testConstructor(cout);
	testConstructor2(cout);
	return 0;
}

void testConstructor(ostream& out)
{
	out << "<!--Testing Constructor-->" << endl;
	MyString A;
	out << A.toString();
}

void testConstructor2(ostream& out)
{
	out << "<!--Testing Constructor by Value-->" << endl;
	MyString A;
	MyString B("Bobby");
	out << A.toString();
	out << B.toString();
}