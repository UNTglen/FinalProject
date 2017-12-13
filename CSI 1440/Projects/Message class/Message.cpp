/*****************************************************************
  FileName: Message.cpp
  Author:	Glen Newell
  Description:  To creat a Message class capable of handeling up 
	to a 1000 Messages.

  File Modifide: 20061127
		-File Created
  File Modifide: 20061128
		-Edited Some of the Funtions in the class
*****************************************************************/
#include "Message.h"

int Message::messageIDGen = 0;

/****************************************************************
*
*	Class: Message
*   Function: Message
*   Description: contructor
*
****************************************************************/
Message::Message(string Date, string Sender, string Recipient, string Body)
{	

	messageID = ++messageIDGen;
	date=setDate(Date);
	sender = Sender;
	recipient = Recipient;
	body = Body;
}

/****************************************************************
*
*	Class: Message
*   Function: ~Message
*   Description: Destructor
*
****************************************************************/
Message::~Message()
{

}

/****************************************************************
*
*	Class: Message
*   Function: setSender
*   Description: Modifier that allows the user to set the 
*   sender string
*
****************************************************************/
void Message::setSender(string Sender)
{
	sender=Sender;
}

/****************************************************************
*
*	Class: Message
*   Function: setSender
*   Description: Modifier that allows the user to set the 
*   recipient
*
****************************************************************/
void Message::setRecipient(string Recipient)
{
	recipient=Recipient;
}

/****************************************************************
*
*	Class: Message
*   Function: setBody
*   Description: Modifier that allows the user to set the Body
*
****************************************************************/
void Message::setBody(string Body)
{
	body=Body;
}

/****************************************************************
*
*	Class: Message
*   Function: setDate
*   Description: Modifier that allows the user to set the date
*
****************************************************************/
void Message::setDate(string Date)
{
	date=Date;
}

/****************************************************************
*
*	Class: Message
*   Function: getSender
*   Description: Accessor that allows the user to get the 
*   sender string
*
****************************************************************/
string Message::getSender()
{
	return sender;
}

/****************************************************************
*
*	Class: Message
*   Function: getRecipient
*   Description: Accessor that allows the user to get the 
*   recipient string
*
****************************************************************/
string Message::getRecipient()
{     
	return recipient;
}

/****************************************************************
*
*	Class: Message
*   Function: getBody
*   Description: Accessor that allows that user to get the 
*   Body string
*
****************************************************************/
string Message::getBody()
{     
	return body;
}

/****************************************************************
*
*	Class: Message
*   Function: getDate
*   Description: Accessor that allows the user to get the
*   date string
*
****************************************************************/
string Message::getDate()
{     
	return date;
}

/****************************************************************
*
*	Class: Message
*   Function: toString
*   Description: Function that returns a string representation 
*   of a message object
*
****************************************************************/
string Message::toString()
{
	//use the function getStringMessageID, the members of the class
	string result = "Message #" + getStringMessageID() 
	+ "\nDate: " + date + "\nSender: " + sender + "\nRecipient: " 
	+ recipient + '\n' + body; //and then the body of the message

	return result;
}

/****************************************************************
*
*	Class: Message
*   Function: getStringMessageID
*   Description: We have no idea what this does lol
*
****************************************************************/
string Message::getStringMessageID()

{
	ostringstream temp;
	temp << messageID;      
	return temp.str();      
}

