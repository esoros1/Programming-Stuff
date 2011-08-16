//Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
//where a floating-point number may be followed by e or E and an optionally signed exponent.
#include <stdio.h>
#include "calc.h"

int main()
{
	double c;
	while( (c = getNextOperator("1 2 - 4 5 + *")) != EOF ) 
	{
		if (c == '+')
			push(pop() + pop());
		else if (c == '-')
		{
			double rhs = pop();
			double lhs = pop();
			push(lhs - rhs);
		}
		else if (c == '*')
			push(pop() * pop());
		else if (c == '/')
		{
			double rhs = pop();
			double lhs = pop();
			push(lhs / rhs);
		}
		//else, it's a number, and just push it
		else
			push(c);
	}
	
	printf("%g\n",pop());
}




