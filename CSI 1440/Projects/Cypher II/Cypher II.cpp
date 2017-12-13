
/*************************************************************
  Filename:	Cyper II.cpp
  Author:	Glen Newell
  Description: To encrypt and decrypt files.

  File modifide: 20061002
	-File Created

  File modifide: 20061003
	-added menu loop

  File modifide: 20061004
	-added recyle loop

  File modifide: 20061005
	-added open file command

  File Modifide 20061007
	-removed recyle loop
	-still trying to figure out encryption and decryption
*************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	char menu; //defines chars
	string encryptFile, decryptFile; //defines strings
	string keyword="";
	int x = 0;
	char c = '\0', d = '\0';
	
	while(true)//loops if menu is false and when completes
	{
		do//intial menu display
		{
			cout << "What would you like to do?" << endl 
			<< endl << "1. Encrypt" << endl << "2. Decrypt"
			<< endl << "3. Quit" << endl << endl 
			<< "Please make a selection 1-3: ";

			cin >> menu;
			cout << endl;
		}
		//menu options
		while((menu !='1')&&(menu !='2')&&(menu !='3'));
		
		//input and output files defined
		ifstream inFile;
		ofstream outFile;

			switch(menu) //menu
			{
			//Case for Encryption
			case '1': cout << endl 
				  <<"Enter the input filename:";
			cin >> decryptFile; 
		
			//output file
			cout << endl 
				<< "Enter the output filename: ";
			cin >> encryptFile; 
	
			//keyword
			cout << endl 
				<<"Enter the keyword (maximum of 6 charecters): ";
			cin.width(7);
			cin >> keyword;
			
			
			inFile.open(decryptFile.c_str());
			outFile.open(encryptFile.c_str());
			//checks to see if inFile opens correctly
				if(!inFile)
				{ 
					cout << "file did not open correctly" << endl;
					break;
				}
				else	
			
				//checks to see if outFile opens correctly
				if(!outFile)
				{ 
					cout << "file did not open correctly" << endl;
					break;
				}
				else	
								
				while (inFile.get(c)) 
					{
						outFile << static_cast<char>(c + keyword[x]);
						++x;
						if (x >= keyword.length()) 
						{
							x = 0;
						}
					}				


				//clears in and out files
				inFile.clear();
				outFile.clear();

				//closes in and out files
				inFile.close();
				outFile.close();
				cout << endl;
			break;


			//Case for Decryption
			case '2': cout << endl <<"Enter the input filename:";
			cin >> encryptFile; 
			
			//output file
			cout << endl << "Enter the output filename: ";
			cin >> decryptFile; 

			//keyword
			cout << endl 
				<<"Enter the keyword (maximum of 6 charecters): ";
			cin.width(7);
			cin >> keyword;	

			//opens input file & checks to see if opens
			inFile.open(encryptFile.c_str());
			//opens output file & checks to see if opens	
			outFile.open(decryptFile.c_str());

			if(!inFile)
				{ 
					cout << "file did not open correctly" << endl;
					break;
				}
			else

			if(!outFile)
				{ 
					cout << "file did not open correctly" << endl;
					break;
				}
			else

			//reads in file
			//decrypts file
			while (inFile.get(d)) 
					{
						outFile << static_cast<char>(d - keyword[x]);
						++x;
						if (x >= keyword.length()) 
						{
							x = 0;
						}
					}

				//clears in and out files
				inFile.clear();
				outFile.clear();
				//closes in and out files
				inFile.close();
				outFile.close();
				cout << endl;
			break;

			//Case for Quit
			case '3': return 0;

			//Case for any other value
			default: 
			cout << "Invalid Selection. Please choose again!"
					<< endl << endl;
			}//end memu switch
 
	}	
return 0;
}

	
