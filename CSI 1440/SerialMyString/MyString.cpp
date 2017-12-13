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
*******************************************************************/
 
#include "MyString.h"	
/******************************************************************
 
   Function Name: MyString()
   Author: Glen Newell
   Type: Default constructor
   Description: Creates an instance of MyString with no peramiters
*******************************************************************/
MyString::MyString()
	{
		size = 0; //eqaul to length of word
		capacity = size+1; //capacity string can hold
 		data = new char[capacity]; //creates an array the size of the word +1
		data[0]='\0';
 	}
 
/******************************************************************
 
   Function Name: Mystring(char*)
   Author: Glen Newell
   Type: Convertion constructor
   Description: constructor with an initialization char string
*******************************************************************/
MyString::MyString(char* in)
	{
		size = strlen(in);
	 	capacity = size +1;
 		data = new char[capacity];
		strcpy(data, in);
	}
	
/******************************************************************

  Function Name: Mystring (const MyString&)
  Author: Glen Newell
  Type: Copy Constructor
  Description: Constructor that takes in a string and creats a copy
*******************************************************************/
MyString::MyString(const MyString& other)
	{
		size = other.size;
		capacity = other.capacity;
		data= new char[capacity];
		strcpy(data, other.data);
		data[size] = '\0';
	}

/******************************************************************

  Function Name: ~MyString
  Author: Glen Newell
  Type: Deconstructor
  Description: Deallocates all memory used
*******************************************************************/
MyString::~MyString()
	{
		delete [] data;
	}

/******************************************************************

  Function Name: operator =
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: Overloaded assignment operator that makes copy of
	MyString Object
*******************************************************************/
MyString MyString::operator = (const MyString& other)
	{ 
		if(this != &other)
		{	
			delete [] data;
			size=other.size;
			capacity = other.size+1;
			data= new char[capacity];
			strcpy(data, other.data);
		}
	
		return *this;
	}
 
/******************************************************************

  Function Name: Append(const Mystring&)
  Author: Glen Newell
  Type: Concatenator
  Description: Append (concatenates) the Mystring other onto the
	end of the this object
*******************************************************************/
MyString& MyString::append(const MyString& other)
	{	
		size += other.size;

		while(capacity <= size)
		{
			grow();
		}

		strcat(data, other.data);
		return *this;
	}

/******************************************************************

  Function Name: MyString::erase()
  Author: Glen Newell
  Type: Erase 
  Description: Sets size to 0 and data[0] to '\0'
*******************************************************************/
MyString& MyString::erase()
	{
		size = 0;
		//capacity = size+1;
 		data[size] = '\0';
		return *this;
	}

/******************************************************************

  Function Name: operator + (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description:Create a new MyString Object that is a concatenation
	of two MyString objects.
*******************************************************************/
MyString MyString::operator + (const MyString& other) const
	{
		MyString temp;

		while(temp.capacity <= size + other.size)
		{
 			temp.grow();
 		}

		strcpy(temp.data, data);
		strcat(temp.data, other.data);

		temp.size = size + other.size;

		return temp;
	}

/******************************************************************

  Function Name: operator == (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: overloaded equivalence relational operator
*******************************************************************/ 
bool MyString::operator == (const MyString& other)
	{
		return strcmp(data, other.data) == 0;
	}
 
/******************************************************************

  Function Name: operator < (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: returns true if the this object is less than the 
	MyString s, false otherwise
*******************************************************************/
bool MyString::operator <  (const MyString& other)
	{
		return strcmp(data, other.data) < 0;
	}
 
/******************************************************************

  Function Name: operator > (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: returns true if the this object is greater than the 
	MyString s, false otherwise
*******************************************************************/
bool MyString::operator >  (const MyString& other)
	{
		return strcmp(data, other.data) > 0;
	}
 
/******************************************************************

  Function Name: operator <= (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: returns true if the this object is less than or equal
	to the MyString s, false otherwise
*******************************************************************/
bool MyString::operator <= (const MyString& other)
	{
 		return strcmp(data, other.data) <= 0;
	}
 
/******************************************************************
 
  Function Name: operator >= (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: returns true if the this object is greater than or 
	equal to the MyString s, false otherwise
*******************************************************************/
bool MyString::operator >= (const MyString& other)
	{
		return strcmp(data, other.data) >= 0;
	}

/******************************************************************

  Function Name: operator != (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: returns true if the this object is not equal to the
	MyString s, false otherwise
*******************************************************************/
bool MyString::operator != (const MyString& other)
	{
		return strcmp(data, other.data) != 0;
	}

/******************************************************************

  Function Name: operator += (const MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: used to concatenate the MyString other to the end 
	of this object. 
*******************************************************************/ 
void MyString::operator += (const MyString& other)
 	{
 	//	size += other.size;
 		append(other);
 	}
 
/******************************************************************

  Function Name: operator [] (int)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: returns char by refrance
*******************************************************************/
char& MyString::operator [] (int n)
 	{
 		return data[n];
	}
 
/******************************************************************

  Function Name: getline(istream&)
  Author: Glen Newell
  Type: Get function
  Description: reads an entire line from istream. 
*******************************************************************/
void MyString::getline(istream& in)
 	{
		size = 0;
		char ch;
 
 		while(in.get(ch) && ch != '\n')
		{
 			if(size + 1 >= capacity) grow();		
			
			data[size] = ch;
			size++;
		}
	     data[size] = '\0';
	}

/******************************************************************

  Function Name: length()
  Author: Glen Newell
  Type: Sizing function
  Description: returns the length of the string, not including the
	NULL char
*******************************************************************/
int MyString::length() const
	{
 		return size;
	}

/******************************************************************

  Function Name: operator<< (ostream&, MyString&)
  Author: Glen Newell
  Type: Overloaded assignment opperator
  Description: insertion operator
*******************************************************************/
ostream& operator<< (ostream& out, MyString& other)
	{
		out << other.data;
		return out;

	}

/******************************************************************

  Function Name: grow()
  Author: Glen Newell
  Type: growing function
  Description: doubles capacity
*******************************************************************/
void MyString::grow()
	{
 		capacity *= 2;
		char *point = new char[capacity];
		strcpy(point, data);
		delete [] data;
		data = point;
	}

/******************************************************************
 
  Function Name: shrink()
  Author: Glen Newell
  Type: shrinking function
  Description: deducts capacity by half 
*******************************************************************/
void MyString::shrink()
	{
		while(size <= .25 * capacity);
		{
			capacity /= 2;
			char *point = new char[capacity];
			strcpy(point, data);
			delete [] data;
			data = point;
		}
	}

