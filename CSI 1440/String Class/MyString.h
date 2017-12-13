#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class MyString;
ostream& operator<< (ostream&, MyString&);

class MyString
{
private:
	int size;
	int capacity;
	char* data;

public:
	MyString();
	MyString(char*);
	MyString(const MyString &);
	~MyString();
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
	
	friend ostream& operator<< (ostream&, MyString&);	

};



#endif
