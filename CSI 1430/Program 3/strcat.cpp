#include <iostream>
//#include <cstring>
using namespace std;

int strlen(char*); 
char *strcat(char*, char*);
char* strcpy(char*, char*);
int strcmp(const char*, const char*);
char* strstr(char*, char*);
bool check(char*, char*);



int main()
{
   char word[25] = "Hello World";
   char word1[20] = "Hello World";
   cout << strlen(word1) <<endl;
   cout << strcpy(word, word1) <<endl;
   cout << strcmp(word, word1) <<endl;;
   cout << strcat(word, word1) <<endl;

   char river[20] ="Hello World";
   char word2[10] ="bob";
   cout << strstr(river, word2) <<endl;
   

   return 0;
}




char* strcat(char *s1, char *s2) //my version...
{
 
 int size1 = strlen(s1);
 int size2 = strlen(s2);

 for(int i = 0; i < size2; i++)
 {
  s1[size1] = s2[i];
  size1++;
 }
 
 return s1;
 
}



int strlen(char* str)
{
	int count = 0;

	while(str[count])
	{
		count++;
	}

	return count;
}



char* strcpy(char *s1, char *s2)
{
   int size = strlen(s2);
   for(int i=0; i<size; i++) //true not null
	{
	  s1[i]=s2[i];
   }

	return s1;
}




int strcmp(char *s1, char *s2)
{
	while(*s1 && *s1==*s2)
	{
		s1++;
		s2++;
	}

	return *s1-*s2;
}




char* strstr(char *s1, char *s2)
{
	bool done = false;//pointer to see if you found what you were looking for

	 while(*s1 && !done) // while the source has letters and we havent found it
	 {
		 if(*s1 == *s2) //if pointer1 == poiter 2 then check 
		 {
			 done = check(s1,s2); //see check function below			 
		 }
		 if(!done)s1++; 
	 }

	 return s1;
}



bool check(char *s1, char *s2) //true or false
{
	int n = strlen(s2);

	while(n > 0 && *s1 && *s1==*s2)
	{
		n--;
		s1++;
		s2++;
	}

	return (*s1-*s2);
}



