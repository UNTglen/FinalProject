/*******************************************************************
 
   File Name: SerialMyString.h
   Author: Glen Newell
   Discrition: 
 
   Date Modifide: 20070321
 	- File created
   Date Modifide: 20070321
 	- Wrote functions
 	- Upload fail
   Date Modifide: 20070322
 	- Added function definitions
 	- Upload fail
   Date Modifide: 20070323
 	- Edited the function definitions and put them inside the class
 	- Upload sucessful

*******************************************************************/

#ifndef SERIALMYSTRING_H
#define SERIALMYSTRING_H

#include "MyString.h"
#include "SerializableIfc.h"

class SerialMyString : public MyString, public SerializableIfc

{
private:

public:
/******************************************************************

  Function Name: writeOject
  Author: Glen Newell / Bill Booth
  Type: Output object
  Description: Outputs a serial string that has been reinterpreted
	to a char. 
*******************************************************************/
	void writeObject(OObjectStream & out)
	{
		out.write(reinterpret_cast<char*>(&size),sizeof(int));
		out.write(reinterpret_cast<char*>(&capacity),sizeof(int));
		delete [] data;
		data = new char[capacity];
		out.write(data,size);
	};

/******************************************************************

  Function Name: readOject
  Author: Glen Newell / Bill Booth
  Type: Input object
  Description: Reads in a binary file and reinterprets then char's
	with in the file to a readable string. 
*******************************************************************/
	void readObject(IObjectStream & in)
	{
		in.read(reinterpret_cast<char*>(&size),sizeof(int));
		in.read(reinterpret_cast<char*>(&capacity),sizeof(int));
		delete [] data;
		data = new char[capacity];
		in.read(data,size);
		data[size]='\0';
	};


};






#endif



