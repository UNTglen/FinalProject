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
#include "proj3-MyString.hpp"
#include <cctype>

/*Brief description
*@This is the constructor used for building MyString
*@peram capacity = 1 for NULL
*@peram data = is the data of the string
*/
MyString::MyString()
{
	capacity = 1;
	data = new char[capacity];
	data[0] = '\0';
}

/*Brief description
*@This is the constructor used for building MyString
*@peram in is a char* that is the string to overload
*	the constructor
*@peram capacity = 1 for NULL
*@peram data = is the data of the string
*@peram StrLng messures size of string
*@peram count is a count for size of string
*/
MyString::MyString(char* in)
{
	int count = 0; 
	char* other = in;
	count = StrLng(in)+1;
	this->capacity = count; 
	data = new char[capacity];
	for(int a = 0; a < capacity; a++)
	{
		this->data[a] = other[a];
	}

}

/*Brief description
*@This is the deconstructor
*@peram data = is the data of the string
*@peram delete: deletes data of MyString
*/
MyString::~MyString()
{
	delete [] data;
}

MyString::MyString(const MyString& other)
{
	capacity = other.capacity;
	data= new char[capacity];
	//StrCpy(data, other.data);
	for(int a = 0; a < capacity; a++)
	{
		this->data[a] = other.data[a];
	}

	data[capacity] = '\0';
}

int MyString::length() const
{
	return (capacity-1);

}

/*Brief description
*@This is the overloaded = operator that is used 
*	for setting one MyString to anouther MyString
*@peram other is the MyString being passed in
*@peram capacity = size of string
*@peram data = is the data of the string
*@peram StrLng messures size of string
*@peram count is a count for size of string
*@peram a is a count to set data of one to other
*/
MyString MyString::operator=(const MyString& other)
{
	if(this != &other)
	{
		delete [] data;
		this->capacity = other.capacity;
		this->data= new char[capacity];
		
		for(int a = 0; a < capacity; a++)
		{
			this->data[a] = other.data[a];
		}
	}

	return *this;
}


/*Brief description
*@This is the overloaded = operator that is used 
*	for setting one MyString to anouther MyString
*@peram in is a char* that is the string to overload
*	the other MyString
*@peram capacity = is size of MyString
*@peram data = is the data of the string
*@peram StrLng messures size of string
*@peram count is a count for size of string
*/
MyString MyString::operator=(char* in)
{
	if(data != '\0')
	{	

		delete [] data;
		int count = 0; 
		char* other = in;
		count = StrLng(in)+1;
		this->capacity = count; 
		data = new char[capacity];
		for(int a = 0; a < capacity; a++)
		{
			this->data[a] = other[a];
		}
	}

	return *this;
}

/*Brief description
*@This is the overloaded != operator that is used to see if 
*	one MyString is not equal to anouther MyString
*@peram other is the MyStringthat is used for setting one 
*	MyString to anouther MyString
*@peram StrCmp is a function used to compare the data of
*	one MyString to anouther
*/
bool MyString::operator!=(const MyString& other)
{
	return StrCmp(data, other.data) != 0;
}

/*Brief description
*@peram other is the MyString that is used for testing to see if
*	one MyString is the same as anouther MyString
*@peram StrCmp is a function used to compare the data of
*	one MyString to anouther
*/
bool MyString::operator==(const MyString& other)
{
	return StrCmp(data, other.data) == 0; //write strcmp
}

/*Brief description
*@peram in is the MyString that is used for testing to see if
*	one MyString is the same as anouther MyString
*@peram StrCmp is a function used to compare the data of
*	one MyString to anouther
*/
bool MyString::operator==(char* in)
{
	return StrCmp(data, in) == 0;
}

/*Brief description
*@This is the overloaded [] operator
*@peram data is that data element wanted to return
*@peram x is the number for the elemetn to be returned
*/
char MyString::operator[] (int x)
{
	return data[x];
}

/*Brief description
*@This is a function to concatenate 2 Mystrings together
*@peram capacity = size of string
*@peram append is a function used to bring concatenate
*/
void MyString::operator+=(const MyString& other)
{
	capacity += other.capacity;
	append(other);
}


/*void MyString::operator+=(char* m)
{
	return;
}*/

/*Brief description
*@This is a function that reads in a token from an istream
*@peram in is the istream reading in from
*@peram ch is a char that you can read into
*@peram c is an intager that is used as a counter, smaller 
*	capacity
**peram isspace is checking to see if its white space
*/
void MyString::getToken(istream& in)
{
	char ch;
	int c = 0;
	while(!isspace(c))
	{
		in.get(ch);
		if(c+1 >= capacity)
		{
			grow();
		}
		data[c] = ch;
		c++;
	}
	return;
}

/*Breif description
*@This function is used to get a line of chars's from a file
*@peram in is the data that you pass into the function
*@peram int size, is a default value counter
*@peram get is a funtion in the cstlib used to get char's
*/
void MyString::getLine(istream& in)
{
	int size = 0;
	char ch;

	while(in.get(ch) && ch != '\n')
	{
		if(capacity + 1 >= capacity) grow();		
		
		data[size] = ch;
		size++;
		data[size] = '\0';
	}
}

/*Breif description
*@This function is used to serialize the MyString into a file
*@peram out is an ostream that you are writing to
*@peram other, is the MyString you are writing tofile
*/
/*static ostream& writeObject(const MyString& other, ostream& out)
{
	out.write((char*)&other.capacity,sizeof(other.capacity));
	out.write((char*)&other.data,other.capacity*sizeof(char));
}*/

/*Breif description
*@This function is used to deserialize the MyString from a file
*@peram in is an istream that you are reading from
*@peram other, is the MyString you are reading
*/
/*static MyString& readObject(istream&in)
{
	in.read((char*)&other.capacity,sizeof(other.capacity));
	in.read((char*)&other.data,other.capacity*sizeof(char));
}*/

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

/*Breif description
*@This function is used to grow the amount of memory used
*	if the capacity is more than the amount allocated
*@peram capacity is the size of the data
*@peram point is a temp char pointer that will recive old
*	data in the newly dynamically allocated memory size
*@peram data is the data that needs to be shrunk
*/
void MyString::grow()
{
	int size = capacity; 
	capacity *= 2;
	char *point = new char[capacity];
	for(int a = 0; a < size; a++)
	{
		point[a] = this->data[a];
	}
	delete [] data;
	data = point;

}

/*Breif description
*@This function is used to shrink the amount of memory used
*	if the memory is less than .25 of capacty
*@peram capacity is the size of the data
*@peram point is a temp char pointer that will recive old
*	data in the newly dynamically allocated memory size
*@peram data is the data that needs to be shrunk
*/
void MyString::shrink()
{
	while(capacity <= .25 * capacity);
	{
		int size = capacity; 
		capacity /= 2;
		char *point = new char[capacity];
		for(int a = 0; a < size; a++)
		{
			point[a] = data[a];
		}	
		delete [] data;
		data = point;
	}
}

/*Breif description
*@This function is used to count how long a string is
*@peram char*s is the data you are passing in
*@peram count is a counter used to count letters
*@peram prt is a pointer to access the char* as int
*/
int MyString::StrLng(const char* s)
{
	int count = 0;
	char* prt = (char*)s;

	while(*prt !=  '\0')
	{
		count++;
		prt++;

	}

	return count;
}

/*Breif description
*@This function is used to 
*@peram 
*/
char* MyString::StrCpy(char *s1, char *s2)
{
	int count = 0;
	int size = StrLng(s2);

	for(int i=0; i<size; i++) //true not null
	{
	  s1[i]=s2[i];
	}

	s1[count] = '\0';
	return s1;
}

/*Breif description
*@This function is used to 
*@peram 
*/
int MyString::StrCmp(char *s1, char *s2)
{
	cout << "comparing" << endl;
	while(*s1 && s1==s2)
	{
		s1++;
		s2++;
	}

	return *s1-*s2;
}

/*Breif description
*@This function is used to 
*@peram 
*/
char* MyString::StrCat(char *s1, char *s2) //my version...
{
 
 int size1 = strlen(s1);
 int size2 = strlen(s2);

 for(int i = 0; i < size2; i++)
 {
  s1[size1] = s2[i];
  size1++;
 }
 
 return s1;
 
}

/*Breif description
*@This function is used to 
*@peram 
*/
MyString& MyString::append(const MyString& other)
{	

	int size = capacity;
	int size2 = other.capacity; 
	while(capacity <= size + size2)
	{
		grow();
	}

	
	int size3 = StrLng(data);
	int size4 = StrLng(other.data);
	int count = size3+size4;

	for(int i = 0; i < size4; i++)
	{
	data[size3] = other.data[i];
	size3++;
	}
	data[count] = '\0';
	
return *this;
}
