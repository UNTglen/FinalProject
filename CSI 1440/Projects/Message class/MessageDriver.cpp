/*****************************************************************
  FileName: MessageDriver.cpp
  Author:	Glen Newell
  Description:  To creat a Message class capable of handeling up 
	to a 1000 Messages.

  File Modifide: 20061127
		-File Created
  File Modifide: 20061128
		-Edited Some of the Funtions in the class
		-Built Driver program
*****************************************************************/

#include "Message.h"

int main()
{
	int messageID;
	string current_line="";
	Message messages[1000];

	//ask and promps user for a message to view
	cout << "Which messageID would you like to view? "; 
	cin >> messageID;
	
	//declares an instream file
	ifstream inFile;
	inFile.open("messages.txt"); //opens messsages.txt
	
	//checks to see if file is found, and displays error if not
	if (!inFile)
	{
		cout << "File not found." << endl;
		return 0;
	}


	//allows only 1000 messages to be entered
	for(int i = 0; i <=999; i++)
	{
		getline(inFile,current_line); //gets date
		messages[i].setDate(current_line);

		getline(inFile,current_line); //gets sender
		messages[i].setSender(current_line);

		getline(inFile,current_line); //gets recipient
		messages[i].setRecipient(current_line);

		getline(inFile,current_line); //gets body
		messages[i].setBody(current_line);

		inFile.ignore(); //skips line
	}
	

	for(int j=0; j <=5; j++) //prints out first 5 messages
	{
		cout << messages[j].toString(); //uses tostring to print out
	}

	return 0;
}
