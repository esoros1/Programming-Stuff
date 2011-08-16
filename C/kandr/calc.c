#include <stdio.h>
#include "calc.h"

int atoi(char num [])
{
	return (int) atof(num);
}

double atof(char num [])
{
	int sign = 1;
	int i = 0;
	//get the sign
	if (num[0] == '-')
	{
		sign = -1;
		++i;
	}
	//get the value before the decimal
	double result = 0.0;
	while(num[i] != '\0' && num[i] != '.')
		result = (result * 10) + (num[i++] - '0');
	
	if (num[i] == '\0')
		return result;

	++i;
	//get the value after the decimal
	double decimal = 0.0;
	double power = 1.0;
	while(num[i] != '\0' && num[i] != 'e' && num[i] != 'E')
	{
		decimal = (decimal * 10) + (num[i++] - '0');
		power *= 10.0;
	}

	result = (result + decimal/power) * sign;
	//se if we have to shift any places
	if(num[i] == '\0')
		return result;
	
	++i;
	if(num[i] == '-')
	{
		int j;
		int n = (num[i+1] - '0');
		for(j = 0; j < n; ++j)
			result /= 10.0;
	}
	else
	{
		int j;
		int n = (num[i] - '0');
		printf("%d\n",n);
		for(j = 0; j < n; ++j)
			result *= 10.0;
	}
	return result;
}

//return the last position that was filled in buffer
int getline(char buffer [], int max)
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
