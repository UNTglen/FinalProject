/***************************************************************************
  Filename: ceaser.cpp
  Authour: Glen Newell
  Description: Do decrypt an encrypted file. 

  File Modifide: 20060906
       -File Created

  File Modifide: 20060908
       -Modifide input and added comments
***************************************************************************/



#include <iostream>
using namespace std;

int main ()
{ 
	//defines charcaters that have been inputed
	char a1, a2, a3, a4, a5, a6, a7, a8, a9, a0, aa, ab;
	char b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, ba, bb;

	cout << "Input 12 characters to be dycrypted:";
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a0 >> aa >> ab;
   
	//changes values of letters
	b1=(a1+3);
	b2=(a2+3); 
	b3=(a3+3); 
	b4=(a4+3);
	b5=(a5+3); 
	b6=(a6+3);
	b7=(a7+3);
	b8=(a8+3);
	b9=(a9+3); 
	b0=(a0+3); 
	ba=(aa+3); 
	bb=(ab+3);

	cout << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << b9 << b0 << ba << bb;

	/*cout <<"The 12 carcters encrypted are: " << static_cast<char>(b1) << static_cast<char>(b2) << static_cast<char>(b3)
		<< static_cast<char>(b4) << static_cast<char>(b5) << static_cast<char>(b6)
		<< static_cast<char>(b7) << static_cast<char>(b8) << static_cast<char>(b9)
		<< static_cast<char>(b0) << static_cast<char>(ba) << static_cast<char>(bb);*/
	
	return 0;
	
	
}

