/*****************************************************************
  FileName: Message.h
  Author:	Glen Newell
  Description:  To creat a Message class capable of handeling up 
	to a 1000 Messages.

  File Modifide: 20061127
		-File Created
*****************************************************************/
#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


/**************************************************************************
*
*	class: Message
*	Discription: A class that stores incoming emails and sorts them 
*
***************************************************************************/
class Message
{ 
	private:
		string sender, recipient, body, date;  
		static int messageIDGen;
		int messageID;

    public:
/**************************************************************************
*
*	class: Message
*	Function: Message
*   Description: Default constructor
*
***************************************************************************/
		Message(){ messageID = ++messageIDGen; };
	

/**************************************************************************
*
*	class: Message
*	Function: Message
*   
*
***************************************************************************/
		Message(string, string, string, string);

/**************************************************************************
*
*	class: Message
*   Function: ~Message
*	Description: Destructor
*
***************************************************************************/
		~Message();


/****************************************************************
*
*	Class: Message
*   Function: setSender
*   Description: Modifier that allows the user to set the 
*   sender string
*
****************************************************************/
		void setSender(string);

/****************************************************************
*
*	Class: Message
*   Function: setRecipient
*   Description: Modifier that allows the user to set the 
*   recipient
*
****************************************************************/
		void setRecipient(string);

/****************************************************************
*
*	Class: Message
*   Function: setBody
*   Description: Modifier that allows the user to set the Body
*
****************************************************************/
		void setBody(string);

/****************************************************************
*
*	Class: Message
*   Function: setDate
*   Description: Modifier that allows the user to set the date
*
****************************************************************/
		void setDate(string);

/****************************************************************
*
*	Class: Message
*   Function: getSender
*   Description: Accessor that allows the user to get the 
*   sender string
*
****************************************************************/
		string getSender();

/****************************************************************
*
*	Class: Message
*   Function: getRecipient
*   Description: Accessor that allows the user to get the 
*   recipient string
*
****************************************************************/
		string getRecipient();

/****************************************************************
*
*	Class: Message
*   Function: getBody
*   Description: Accessor that allows that user to get the 
*   Body string
*
****************************************************************/
		string getBody();

/****************************************************************
*
*	Class: Message
*   Function: getDate
*   Description: Accessor that allows the user to get the
*   date string
*
****************************************************************/
		string getDate();

/****************************************************************
*
*	Class: Message
*   Function: toString
*   Description: Function that returns a string representation 
*   of a message object
*
****************************************************************/
		string toString();
		
/****************************************************************
*
*	Class: Message
*   Function: getStringMessageID
*   Description: We have no idea what this does lol
*
****************************************************************/
		string getStringMessageID();

};


#endif
