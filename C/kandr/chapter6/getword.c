#include <ctype.h>
#include <string.h>
#include <stdio.h>
#define MAXWORD 100


static int ptr = 0;

char * getnextword(char * s)
{
	char result[MAXWORD];
	int result_ptr = 0;
	//if it is the end of the string, set ptr to 0 and return the empty string
	if(s[ptr] == 0)
	{
		ptr = 0;
		result[0] = 0;
		return strdup(result);
	}
	//skip whitespace
	while(isspace(s[ptr]) && s[ptr] != '\n')
		++ptr;
	//if there are letters, add them to result
	while(isalpha(s[ptr])) 
		result[result_ptr++] = s[ptr++];
	result[result_ptr] = 0;
	
	return strdup(result);
}

//return the last position that was filled in buffer
int getline(char * buffer, int max)
{
	int i = 0;
	int c;
	while( (c = getchar()) != '\n' && c != EOF && max > 0)
	{	
		buffer[i++] = c;
		--max;
	}
	buffer[i] = 0;
	return i;
}
