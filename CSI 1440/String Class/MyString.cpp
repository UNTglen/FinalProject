#include "MyString.h"	

MyString::MyString()
	{
		size = 0; //eqaul to length of word
		capacity = size+1; //capacity string can hold
 		data = new char[capacity]; //creates an array the size of the word +1

		for(int i=0; i < capacity; i++)
		{
			data[i]='\0';
		}
	
	}
 
MyString::MyString(char* in)
	{
	 	capacity = strlen(in)+1;
 		data = new char[capacity];
 		strcpy(data, in);
	}
 
MyString::MyString(const MyString& other)
	{
		capacity = other.capacity;
		data= new char[capacity];
		strcpy(data, other.data);
	}

MyString::~MyString()
	{
		delete [] data;
	}

MyString MyString::operator = (const MyString& other)
	{ 
		if(data != other.data)
		{
			if(size != 0)
			{
				delete [] data;
			}

			capacity = other.capacity;
			data= new char[capacity];
			strcpy(data, other.data);
			
			for(int i=0; i < size; i++)
			{
				data[i]=other.data[i];
			}
 
			return *this;
		}
		else
			return *this;
	}
 
MyString& MyString::append(const MyString& other)
	{
		MyString temp;
		data = new char[strlen(data)+strlen(other.data)+1];
		strcpy(data, temp.data);
		strcpy(data, other.data);
		if(size !=0)
		{
			erase();
		}
			
		return *this;
	}

MyString& MyString::erase()
	{
		size = 0;
		capacity = size+1;
		data[size] = '\0';
		return *this;
	}

MyString MyString::operator + (const MyString& other) const
	{
		MyString temp;
		strcpy(data, temp.data);
		strcpy(data, other.data);
			
		return *this;
	}
 
bool MyString::operator == (const MyString& other)
	{
		return strcmp(data, other.data) == 0;
	}
 
bool MyString::operator <  (const MyString& other)
	{
		return strcmp(data, other.data) < 0;
	}
 
bool MyString::operator >  (const MyString& other)
	{
		return strcmp(data, other.data) > 0;
	}
 
bool MyString::operator <= (const MyString& other)
	{
		return strcmp(data, other.data) <= 0;
	}
 
bool MyString::operator >= (const MyString& other)
	{
		return strcmp(data, other.data) >= 0;
	}

bool MyString::operator != (const MyString& other)
	{
		return strcmp(data, other.data) != 0;
	}

void MyString::operator += (const MyString& s)
{
	char *temp = data;
	
	data = new char[strlen(data) + strlen(s.data) + 1];
	strcpy(data, temp);
	strcpy(data, s.data);
	if(length() != 0)
		delete [] temp;
}

char& MyString::operator [] (int n)
	{
		return data[n];
	}
 
void MyString::getline(istream& data)
	{
		//while(data.get(!= '\n');
		return;
	}

int MyString::length() const
	{
		return size;
	}

ostream& operator<< (ostream& out, MyString& other)
	{
		out << other.data;
		return out;

	}



