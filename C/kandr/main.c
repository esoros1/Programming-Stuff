//Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
//where a floating-point number may be followed by e or E and an optionally signed exponent.
#include <stdio.h>
#include "calc.h"
#include "stack.h"
int main()
{

	stackptr s = init_stack(s);
	double c;
	char line [100];

	while((getline(line,100)) > 0)
	{
		while( (c = getNextOperator(line)) != EOF ) 
		{
			if (c == '+')
				push(s,pop(s) + pop(s));
			else if (c == '-')
			{
				double rhs = pop(s);
				double lhs = pop(s);
				push(s,lhs - rhs);
			}
			else if (c == '*')
				push(s,pop(s) * pop(s));
			else if (c == '/')
			{
				double rhs = pop(s);
				double lhs = pop(s);
				push(s,lhs / rhs);
			}
			//else, it's a number, and just push it
			else
				push(s,c);
		}
	}
	printf("%g\n",pop(s));
}




