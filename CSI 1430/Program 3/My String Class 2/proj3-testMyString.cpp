//*********************************************************
/** \File: testMyString.cpp
*
*	\Author: Glen Newell
*	\Author helpers: NA
*
*	\class: MyString
*	\description: 
*
*
*	<ul>
*	  <li>date modifide: 20070930<br>
*		file created
*	  </li>
*/
//*********************************************************
#include <iostream>
#include <sstream>
#include "proj3-MyString.hpp"

using namespace std;

void testConstructor(ostream&);
void testCopyConstructor(ostream&);
void testLength(MyString&,string&, ostream&);
void testOverloadedEQ(ostream&);
void testOverlodedEQQ(ostream&);
void testOverlodedEQQ2(ostream&);
void testOverlodedPlusEQ(ostream&);

int main()
{
	testConstructor(cout); 
		cout << endl;
	testCopyConstructor(cout); 
		cout << endl;
	//testOverloadedEQ(cout);
		//cout << endl;
	testOverlodedEQQ(cout);
		cout << endl;
	testOverlodedEQQ2(cout);
		cout << endl;
	testOverlodedPlusEQ(cout);
		cout << endl;
	return 0;
}

void testConstructor(ostream& out)
{
	out << "<!--Testing Constructor-->" << endl;
	out << "<!-------MyString()------>" << endl;
	MyString A;
	out << A.toString();
}

void testCopyConstructor(ostream& out)
{
	out << "<!--Testing Constructor by Value-->" << endl;
	out << "<!---------MyString(char*)-------->" << endl;
	MyString B("Bobby");
	out << B.toString();
	string A = "bobby";
	testLength(B, A, cout);
}
void testLength(MyString& in, string& data, ostream& out)
{
	out << endl << "<!--Testing length()-->" << endl;
	int size = 0;
	size = in.length();
	out << "The sting is: " << data << endl;
	out << "The size of MyString is: " << size << endl;
}

void testOverloadedEQ(ostream& out)
{
	out << "<!----Testing Overloaded = operator---->" << endl;
	out << "<!-MyString operator=(const MyString&)->" << endl <<endl;
	MyString A;
	out << A.toString() << endl;

	MyString B("I like chicken!");
	out << B.toString() << endl;

	A = B;

	out << "<!--A now is eqaul to B-->" << endl;
	out << A.toString() << endl;
}

void testOverlodedEQQ(ostream& out)
{
	out << "<!--Testing Overloaded == Operator-->" << endl;
	out << "<!-bool operator==(const MyString&)->" << endl;

	bool result; 
	MyString A("Bobby");
	out << A.toString() << endl;
	MyString B("Bobby");
	out << B.toString() << endl;
	MyString C("bobby");
	out << C.toString() << endl;

	result = (A==B);
	
	out << "If answer = 1, then true" << endl;
	out << "If answer = 0, then false" << endl;

	out << "The result of MyString A == MyString B is: " << result << endl;
	result = (A==C);
	out << "The result of MyString A == MyString C is: " << result << endl;

}

void testOverlodedEQQ2(ostream& out)
{
	out << "<!--Testing Overloaded == Operator-->" << endl;
	out << "<!-bool operator==(const MyString&)->" << endl;

	bool result; 
	MyString A("Bobby");
	out << A.toString() << endl;
	char testerTrue[6] ="Bobby";
	out << testerTrue << endl;
	char testerFalse[6] ="bobby";
	out << testerFalse << endl;

	result = (A==testerTrue);
	
	out << "If answer = 1, then true" << endl;
	out << "If answer = 0, then false" << endl;

	out << "The result of MyString A == testerTrue is: " << result << endl;
	result = (A==testerFalse);
	out << "The result of MyString A == testerFalse is: " << result << endl;

}

void testOverlodedPlusEQ(ostream& out)
{
	out << "<!--Testing Overloaded += Operator-->" << endl;
	out << "<!-bool operator+=(const MyString&)->" << endl;

	MyString A("Bobby");
	out << A.toString() << endl;
	MyString B(" is cool!");
	out << B.toString() << endl;

	A+=B;
	out << A.toString() << endl;

}