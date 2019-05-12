#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	
	//I'm going to get a random character then get the mod of 128, that way I can type cast to an ASCII
	//character in the next line.
    int charInt = random() % 128;
    char charChar = (char)charInt;

    return charChar;
}

char *inputString()
{
	
	
	//i capped the string length at 100 of random lengths because of seg faults.  
	int randomInt = random() % 10;
	char *returnString;
	if(randomInt == 0)
	{
		printf("reset\0");
		strcpy(returnString, "reset\0");
	}
	else if(randomInt >=1){
		int stringLength = randomInt;
		int i;
		for(i =0; i < stringLength; i++){
			char c = inputChar();
			strcat(returnString, c);
		}
	}
	else
	{
		printf("OK, you had a negative number, which is an error\n");
		strcpy(returnString, "OK\n");
	}
    return returnString;
    
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  int i;
  for(i=0; i <100; i++)
  {
    tcCount++;
    c = inputChar();
    if(c == '\0')
    {
    	printf("Error, c is an end of file\n");
     }
    else if(c == '!')
    {
    	printf("Error, c is yelling at me\n");
    }
    else
    {
    	printf("NO ERROR\n");
    }
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0)
    {
    	printf("State = 1\n");
    	state = 1;
 	}	
    if (c == '(' && state == 1)
    {
    	printf("State = 2\n");
    	state = 2;
 	}
    if (c == '{' && state == 2) 
    {
    	printf("State = 3\n");
    	state = 3;
 	}
    if (c == ' '&& state == 3)
    {
    	printf("State = 4\n");
    	state = 4;
 	}
    if (c == 'a' && state == 4) 
    {
    	printf("State = 5\n");
    	state = 5;
 	}
    if (c == 'x' && state == 5) 
        {
    	printf("State = 6\n");
    	state = 6;
 	}
    if (c == '}' && state == 6) 
        {
    	printf("State = 7\n");
    	state = 7;
 	}
    if (c == ')' && state == 7)
        {
    	printf("State = 8\n");
    	state = 8;
 	}
    if (c == ']' && state == 8)
        {
    	printf("State = 9\n");
    	state = 9;
 	}
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error input was to reset ");
      exit(200);
    }
    s = NULL;
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
