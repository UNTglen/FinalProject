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
*	  <li>date modifide: 20070927<br>
*		having a heap error
*		 - Debug assertion failed!
*		 - File: dbgheap.c
*		 - Line: 1044
*		 - error message: _CtrIsValidHeapPointer(PUserData)
*		problem in strcpy fixed
*	  </li>
*	  <li>date modifide: 20070925<br>
*		file created
*	  </li>
*/
//*********************************************************
#ifndef PROJ3_MYSTRING_H
#define PROJ3_MYSRTING_H

#include <iostream>
#include <sstream>
#include "proj3-ObjectIfc.hpp"

class MyString : public ObjectIfc
{
private:
	int capacity;
	char* data;

public:
	MyString();
	MyString(char*);
	virtual ~MyString();
	MyString(const MyString&);

	int length() const;
	MyString operator=(const MyString&);
	MyString operator=(char*);
	
	bool operator==(const MyString&);
	bool operator==(char*);

	bool operator!=(const MyString&);
	
	char operator[](int);

	void operator+=(const MyString&);
	//void operator+=(char*);

	void getToken(istream&);
	void getLine(istream&);

	static ostream& writeObject(const MyString&, ostream&);
	//static MyString& readObject(istream&);
	string toString();

protected:	
	void grow();
	void shrink();
	int StrLng(const char* str);
	char* StrCpy(char *s1, char *s2);
	int StrCmp(char *s1, char *s2);
	char* StrCat(char *s1, char *s2);
	MyString& append(const MyString& other);	

};

#endif

