//*********************************************************
/** \File: myString.hpp
*
*	\Author: Glen Newell
*	\Author helpers: NA
*
*	\class: MyString
*	\description: 
*
*
*	<ul>
*	  <li>date modifide: 20070925<br>
*		file created
*	  </li>
*/
//*********************************************************
#ifndef MYSTRING_H
#define MYSRTING_H

#include <iostream>
#include <sstream>
#include "ObjectIfc.hpp"

class MyString : public ObjectIfc
{
private:
	int capacity;
	char* data;
public:
	MyString();
	Mystring(char* in);
	int length() const;

	~MyString();
	MyString(const MyString& other);

	/*MyString operator=(const MyString& other);
	MyString operator=(char* in);
	
	bool operator==(const MyString& other);
	bool operator==(char* in);
	
	char* operator[](int);

	void operator+=(const MyString& other);
	void operator+=(char* in);

	//void getToken(istream&);
	//void getLine(istream&);

	//static ostream& writeObject(const MyString&, ostream&);
	//static MyString& readObject(istream&);*/
	string toString();
protected:	
	void doubleSize();
	int StrLng(const char* str);

};

#endif
