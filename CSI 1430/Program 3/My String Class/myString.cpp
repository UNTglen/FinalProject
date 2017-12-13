//*********************************************************
/** \File: myString.cpp
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
*		giving default returns of no value
*		file created
*	  </li>
*/
//*********************************************************
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "myString.hpp"

using namespace std; 

MyString::MyString()
{
	capacity = 1;
	data = new char[capacity];
	data = "\0";
}

MyString::Mystring(char* in)
{
	capacity = strlen(in);
	capacity += 1;
	data = new char[capacity];
	strcpy(data, in);
}

int MyString::length() const
{
	return 2;

}

MyString::~MyString()
{
	delete [] data;
}

MyString::MyString(const MyString& other)
{
	capacity = other.capacity;
	data= new char[capacity];
	strcpy(data, other.data);
	data[capacity] = '\0';
}

MyString MyString::operator=(const MyString& other)
{
	return *this;
}

MyString MyString::operator=(char* m)
{
	return *this;
}

bool MyString::operator==(const MyString& other)
{
	return true;
}

bool MyString::operator==(char*)
{
	return true;
}

char* MyString::operator[] (int x)
{
	return data;
}

void MyString::operator+=(const MyString& other)
{
	return;
}

void MyString::operator+=(char* m)
{
	return;
}

/*void MyString::getToken(istream& in)
{
	char ch;
	int c = 0;
	while(in.get(ch) && in != " ")
	{
		in >> ch[c];
		c++;
	}
	return;
}

void MyString::getLine(istream& in)
{
	char ch;
	int c = 0;
	while(in.get(ch) && in !="\0")
	{
		if(c + 1 > capacity)
		{
			doubleSize();
		}

		in >> ch[c];
		c++;
	}

	data[c] = "\0";
}*/

//static ostream& writeObject(const MyString&, ostream&);
//static MyString& readObject(istream&);

/*Breif description
*@This function is used to display the contents of MyString
*@peram out is an ostringstream that is a streaming sting
*	used to display the contents of the MyString and class
*	name, address, and the string value
*/
string MyString::toString()
{
	//creates ostringstring called out
 	ostringstream out;
	
	out << "<CLASS  name =\"MyString\" address=\"" 
		<< this << "\">" << endl;

	out << "<VAR name=\"capacity\" type=\"int\" >" <<this->capacity
		<< "</VAR>" << endl;

	out << "<VAR name=\"data\" type=\"char\" >" <<this->data
		<< "</VAR>" << endl;
 	
	out <<"</CLASS>" << endl;
 	return out.str();
}

void MyString::doubleSize()
{

}

int MyString::StrLng(const char* str)
{
	int count = 0;
	char* prt = (char*)str;

	while(prt!="\0")
	{
		count++;
		prt++;
	}

	return count;
}


