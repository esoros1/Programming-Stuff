//counts the number of words, characters and lines in the 
//file or input. Exercise from K & R
#include <stdio.h>

#define IN	1
#define OUT	0

int main()
{
	int state,numLines,numChars,numWords,c;
	state = OUT;
	numChars = numWords = 0;
	numLines = 1;
	while( (c = getchar()) != EOF)
	{
		++numChars;
		if (c == '\n')
			++numLines;
		if (c == '\n' || c == '\t' || c == ' ')
			state = OUT;
		else if (state == OUT)
		{
			++numWords;
			state = IN;
		}
	}


	printf("\nNumber of Characters: %d\n",numChars);
	printf("Number of Lines: %d\n",numLines);
	printf("Number of Words: %d\n",numWords);
}	
