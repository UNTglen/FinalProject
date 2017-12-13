#include "MyString.h"

MyString::MyString()
	{
		size = 0;
		capacity = 1;
		data=new char[size];

	}

MyString::MyString(char*)
	{
		size = 0;
		capacity = 1;
		data=new char[size];
	}

MyString::MyString(const MyString & other)
	{
		size=other.size;
		capacity=other.capacity;
		data=new char[size];
		for(int i = 0; i < size; i++)
		{
			data[i]=other.data[i];
		}
	}

MyString::~MyString()
	{
		delete data;
	}

MyString MyString::operator = (const MyString& other)
	{
		size=other.size;
		capacity=other.capacity;
		data=new char[size];
		for(int i = 0; i < size; i++)
		{
			data[i]=other.data[i];
		}
		return *this;
	}

MyString& MyString::append(const MyString& s)
	{		
		while(s) 
		{
			s++;
		}

		return *this;
	}

/*MyString::MyString& erase()
	{
		size = 0; 
	}

MyString MySting::operator + (const MyString&) const
	{
		int bob = 1;
		return bob;
	}

bool MySting::operator == (const MyString&)
	{
		return *this;
	}

bool MySting::operator <  (const MyString&)
	{
		return *this;
	}

bool MySting::operator >  (const MyString&)
	{
		return *this;
	}

bool MySting::operator <= (const MyString&)
	{
		return *this;
	}

bool MySting::operator >= (const MyString&)
	{
		return *this;
	}

bool MySting::operator != (const MyString&)
	{
		return *this;
	}

void MySting::operator += (const MyString&)
	{
		return *this;
	}

char& MySting::operator [] (int)
	{
		return *this;
	}

void MySting::getline(istream&)
	{
		return *this;
	}

int MySting::length() const
	{
		int bob = 5;
		return bob;
	}

friend ostream& opperator << (ostream&, MyString&)

	{
		return *this;
	}
*/

