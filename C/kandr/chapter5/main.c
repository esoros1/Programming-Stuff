//Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
//where a floating-point number may be followed by e or E and an optionally signed exponent.
#include <stdio.h>
#include "calc.h"
#include "stack.h"
int main()
{
	char line[100];
	
	while( (getline(line,100)) > 0 )
		printf("%g\n",eval(infixToPostfix(line)));
		
}




