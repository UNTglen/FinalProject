int strlenBooth(char *s) //booth
{
	int count =0;

	while(*s[count])
	{
		count++
	}

	return count;
}

int strlenAars(char* str) //aars
{
	int count = 0;
	char* prt = str;

	while(*ptr!="\0")
	{
		count++;
		prt++;
	}

	return count;
}

char* strcat(char *s1, char *s2) //my version... 
{
	int count;
	int size1 = strlen(s1);
	int size2 = strlen(s2);
	char *newData[(size1+size2)-1];
	count - 1; // for null terminator
	
	for(count = 0; count < size1; count++)
	{
		newData[count] = s1[count];
	}

	while(*s2)
	{
		newData[count] = *s2;
		count++;
	}

	return *newData;

}


int strcmp(char *s1, char *s2)
{
	while(*s1 && *s1==s2)
	{
		s1++;
		s2++;
	}

	return *s1-*s2;
}

void strcpy(char *s1, char *s2)
{
	while(*s2) //true not null
	{
		*s1=*s2;
		s1++;
		s2++;
	}

	*s1 = "\0";
}

char* strstr(char *s1, char *s2)
{
	bool done = false;
	 while(*s1 && !done)
	 {
		 if(*s1++ == *s2)
		 {
			 done = check(s1,s2); //see check function below
		 }

		 if(!done)
		 {
			 s1++;
		 }
	 }

	 return s1;
}

bool check(char *s1, char *s2)
{
	int n=strlen(52);

	while(n>0 && *s1 && *s1==*s2)
	{
		n--;
		s1++;
		s2++;
	}

	return !(*s1-*s2)
}

	}
}