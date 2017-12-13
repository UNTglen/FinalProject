/***************************************************************************
  Filename: ceaser.cpp
  Authour: Glen Newell
  Description: Do decrypt an encrypted file. 

  File Modifide: 20060906
       -File Created

  File Modifide: 20060908
       -Modifide input method changed to open file
	   -changed name to test.cpp 
	   -added comments
	   -added function to creat dycrpted.txt
	   -added cout to screen for dycrypted.txt
***************************************************************************/



#include <iostream>
#include <fstream>
using namespace std;

int main ()
{ 
	//defindes char for inFile
	ifstream inFile;
	char a1, a2, a3, a4, a5, a6, a7, a8, a9, a0, aa, ab;

	//reads encryted.txt
	inFile.open("encrypted.txt");
	cout << "reading the code................\n\n";

	//processing and stores encrytped.txt	
	inFile >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 
		>> a9 >> a0 >> aa >> ab;

	//displays encryted.txt
	cout << "the encyptions reads as: " << a1 << a2 <<a3 <<a4  
		<< a5 << a6 << a7 << a8 << a9 << a0 << aa << ab << endl;

	//converts each character to the proper letter
	a1 -= 3;
	a2 -= 3;
	a3 -= 3;
	a4 -= 3;
	a5 -= 3;
	a6 -= 3;
	a7 -= 3;
	a8 -= 3;
	a9 -= 3;
	a0 -= 3;
	aa -= 3;
	ab -= 3;

	//displays decyrption file
	cout << "the decyrption reads as: " << a1 << a2 << a3 <<a4  
		<< a5
		<< a6 << a7 << a8 << a9 << a0 << aa << ab << endl;

	//creates and stores decrypted.txt
	ofstream outputFile;
	cout << "storing file as decrypted.txt..........\n\n";
	
	outputFile.open("dectypted.txt");
	outputFile << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8
		<< a9 << a0 << aa << ab;

	//closes encrypted.txt
	inFile.close();

	//closes decrypted.txt
	outputFile.close();
	return 0;
	
	
}

