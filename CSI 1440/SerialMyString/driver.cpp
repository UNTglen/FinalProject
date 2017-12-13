#include <iostream>
using namespace std;

#include "SerialMyString.h"

int main()
{
	SerialMyString one;
    IObjectStream in("serial.bin");
    OObjectStream out("write.bin");
    
    while(!in.eof())
    {
	   one.readObject(in);
	   cout<<one<<endl;
	   one.writeObject(out);
	}
	out.close();
	in.close();
	
cout << "\n\n****************************************\n\n";

	SerialMyString two;
	IObjectStream data("write.bin");
	while(!data.eof())
	{
	  two.readObject(data);
      cout << two << endl; 
    }
    
    data.close();
    
  return 0;
}
