
/*************************************************************

  Filename:	Cyper II.cpp
  Author:	Glen Newell
  Description: To encrypt and decrypt files.

  File modifide: 20061002
	-File Created

  File modifide: 20061003
	-added menu loop

  File modifide: 20061004
	-added recyle loop, bug in other values

*************************************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	char menu, recycle;
	string encryptFile, decryptFile, keyword;

	while(true)
	{
		do
		{
			cout << "What would you like to do?" << endl 
			<< endl << "1. Encrypt a file" << endl 
			<< "2. Decrypt a file"<< endl << "3. Quit" 
			<< endl << endl 
			<< "Please make a selection 1-3: ";

			cin >> menu;
		}
		while((menu !='1')&&(menu !='2')&&(menu !='3'));

			switch(menu) //menu
			{
			//Case for Encryption
			case '1': cout << endl 
				  <<"Please input file name to encrypt: ";
			cin >> encryptFile;
				
			cout << endl 
				<<"Please input file name to output encryption: ";
			cin >> decryptFile;
	
			cout << endl 
				<<"Please input keyword (maximum of 6 charecters): ";
			cin >> keyword;
				
			cout << encryptFile << " " <<decryptFile
				<< " " << keyword << endl;
			cout << endl << "would you like to start over?";
				cin >> recycle;
			break;

			//Case for Decryption
			case '2': cout << "Decrypting" << endl;
			break;

			//Case for Quit
			case '3': return 0;

			//Case for any other value
			default: 
			cout << "Invalid Selection. Please choose again!"
					<< endl << endl;
			}//end memu switch

	do
	{
		cout << "would you like to start over?:";
			cin >> recycle;

		switch(recycle) // Defines recycle switch
			{
			case 'y': cout << endl;
			case 'Y': cout << endl;
			break;

			case 'n': return 0;
			case 'N': return 0;

			default: cout << "invalid selection" << endl
						 <<endl;
				break;
			}//end recycle switch
	}
	while((recycle !='Y')&&(recycle !='N')&&(recycle !='y')
		 &&(recycle !='n'));	 
	}	
return 0;
}
