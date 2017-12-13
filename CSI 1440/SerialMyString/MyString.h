/*******************************************************************
 
   File Name: MyString.cpp
   Author: Glen Newell
   Discrition: Creates the funtions to be used and allocated by 
 	Mystring.cpp
 
   Date Modifide: 20070214
 	- File created
   Date Modifide: 20070215
 	- Created a base case for everthing 
 	- Upload fail
   Date Modifide: 20070216
 	- Built Default construtor
 	- Garbage prints out if NULL char is not used
 	- BLANK, Smith
   Date Modifide: 20070219
 	- Built Constructor with inalization char string
 	- Blank, Smith, Smith
   Date Modifide: 20070220
 	- Built convertion constructor
 	- Fails
   Date Modifide: 20070221
 	- completed Convertion constructor
 	- completed Copy Constructor
 	- Completed all bool based funtions
   Date Modifide: 20070220
 	- Added Comments 
   Date Modifide: 200700321
 	- Added virtual Destructor
   Date Modifide: 20070323
 	- Added protected vs private security
*******************************************************************/
#ifndef MYSTRING_H
#define MYSTRING_H
 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
 
class MyString
{

protected:
 	int size;
	int capacity;
 	char* data;

public:
 	MyString();
 	MyString(char*);
	MyString(const MyString &);
	virtual ~MyString();
	MyString operator = (const MyString&);
 	MyString& append(const MyString&);
 	MyString& erase();
	MyString operator + (const MyString&) const;
	bool operator == (const MyString&);
	bool operator <  (const MyString&);
	bool operator >  (const MyString&);
	bool operator <= (const MyString&);
	bool operator >= (const MyString&);
	bool operator != (const MyString&);
 	void operator += (const MyString&);
	char& operator [] (int);
	void getline(istream&);
	int length() const;
	void grow();
	void shrink();
	
	friend ostream& operator<< (ostream&, MyString&);	
};

#endif
