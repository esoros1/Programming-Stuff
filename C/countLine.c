#include <stdio.h>

//count the number of lines in a file/input
//exercise from K & R

int main()
{
 	
	int numLines = 0;
	int c;

	while( (c = getchar()) != EOF)
		if (c == '\n')
			++numLines;
	printf("Number of Lines: %d\n",numLines);
	
}
