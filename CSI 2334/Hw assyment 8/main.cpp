#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
short myArray[MAX];

void sqrit()
{
        __asm{
                START: lea ebx, myArray
                       mov ecx, MAX
                       mov  dx, 0

                  TOP: cmp  dx, [ebx]
                       jg  LESSTHAN
                       add ebx, 2
                       loop TOP
                       jmp DONE

             LESSTHAN: mov eax, [ebx]
                       imul eax, eax
                       mov [ebx], ax
                       add ebx, 2
                       loop TOP

                 DONE:
        }
}

int main()
{
    cout << "This progam will load an array of ten 16-bit values, replace the"<<
    "negative numbers with their squares then print out the array befor and" <<
    "after" << endl;

    for(int i=0; i < MAX; i++)
    {
        cout << endl << "Input value for position" << i << "of array: ";
        xin >> myArray[i];
    }

    cout << "\n\nThe before value looks like: " << endl;
    for(int i=0; i < MAX; i++)
    {
        cout << "\t\tPosistion [" << i << "] is: " << myArray[i] << endl;
    }

    sqrit();    //call to my function

    cout << "\n\nThe after value looks like: " << endl;
    for(int i=0; i < MAX; i++)
    {
        cout << "\t\tPosistion [" << i << "] is: " << myArray[i] << endl;
    }
	return 0;
}
