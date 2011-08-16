#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int ptr = 0;
//parse the string, and get the next operator
double getNextOperator(char s[])
{
	char num[20];
	int num_ptr = 0;
	//skip over whitespace
	while( isspace(s[ptr]) )
		++ptr;
	//get the next characters
	if(s[ptr] == '+')
	{
		++ptr;
		return '+';
	}
	if (s[ptr] == '-')
	{
		++ptr;
		return '-';
	}
	if(s[ptr] == '*')
	{
		++ptr;
		return '*';
	}
	if(s[ptr] == '/')
	{
		++ptr;
		return '/';
	}
	//else it's either EOF or a number
	if(s[ptr] == 0)
	{
		//set ptr back to zero, as the string is over
		ptr = 0;
		return EOF;
	}
	else
	{
		num[num_ptr++] = s[ptr];
		while( isdigit(s[ptr+1]) || s[ptr+1] == '.')
			num[num_ptr++] = s[++ptr];
		num[num_ptr] = 0;
		++ptr;
		return atof(num);
	}
	return -1;
}
