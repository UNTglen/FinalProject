//*********************************************************
/** \File: main.cpp
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
#include "proj3-ObjectIfc.hpp"

using namespace std;

int main()
{
	//creates default MyString
	cout << "I will now build a default MyString: A" << endl << endl;
	MyString A;
	cout << A.toString() << endl << endl;

	//creates overloded MyString
	cout << "I will now build a MyString B overloaded with Bobby" << endl << endl;
	MyString B("Bobby");
	cout << B.toString() << endl << endl;

	//calls copy constructor to build matrix
	cout << "I will now build MyString C to MyString B, calling Copy Constructor: C(B)" << endl << endl;
	MyString C(B);
	cout << C.toString() << endl << endl;

	//creates overloded MyString
	cout << "I will now build a MyString D overloaded with is Cool!" << endl << endl;
	MyString D(" is Cool!");
	cout << D.toString() << endl << endl;

	//set values of one matrix to anouther
	cout << "I will now set the value of MyString A equal to MyString C: A = C" << endl << endl;
	A = B;
	cout << A.toString() << endl << endl;

	cout << "I will now add the value of D to B" << endl << endl;
	//set values of B to A
	B+=D;
	cout << B.toString() << endl << endl;

	//tests to see if A==C
	cout << "I will now see if the value of MyString A is equal to MyString C" << endl;
	cout << "If anser is true 1 will be returned, if false answer will be 0" << endl << endl;
	bool test;
	test = (A==C);
	cout << test << endl;

	//tests to see if A==D
	cout << "I will now see if the value of MyString A is equal to MyString D" << endl;
	test = (A==D);
	cout << test << endl;

	

	return 0;

}