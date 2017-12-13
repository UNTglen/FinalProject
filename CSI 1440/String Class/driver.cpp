
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyString.h"

using namespace std;

int main()
{
	
	MyString fname;
	MyString lname("Smith");
	MyString mname(lname);
	fname = mname;
	MyString line, paper;
	MyString fullName;
	ifstream inData;
	
	fname = "Bob";

	fname = fname;
	
    cout <<fname<<" "<<mname<<". "<<lname<<endl;
    
    inData.open("paper.txt");
    
    if(!inData)
    {
      cerr <<"Error: File NOT open\n";
      exit(0);
    }
  
    line.getline(inData);
    
    while(!inData.eof())
    {
      line += "\n";
      paper += line;
      line.getline(inData);
    }

    line += "\n";
    paper += line;
    
    cout <<"The paper has a length of "<<paper.length()<<".\n";
    cout << line;
    /*  
    cout << "\n\n\n";
    
    cout << paper;
    
    cout << "\n\n\n";
    
    //Test the = operator
    mname = "A";
    fname = fname + " " + mname + ". " + lname;
    
    fullName = fname;
    
    cout << "Fill Name is :  "<<fullName<<endl;
    
    
    if(fname == fullName)
       cout<<"But the names remain the same\n";
    else
       cout<<"Why did you change your name?\n";
       
    fname = "Mary";  
    if(fname == fullName)
       cout<<"But the names remain the same\n";
    else
       cout<<"Why did you change your name?\n";
       
    for(int index = 0; index < fullName.length(); index++)
       cout << fullName[index] << endl;*/
	return 0;
}
