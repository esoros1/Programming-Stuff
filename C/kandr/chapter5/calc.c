#include <stdio.h>
#include <string.h>
#include "calc.h"
#include "stack.h"

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

//returns true if lhs is of higher presedence than rhs
int isHigherPrecedence(char lhs, char rhs)
{
	int lhsP, rhsP;
	//get lhs precedence
	switch (lhs) {
	case '*':
	case '/':
		lhsP = 2;
		break;

	case '+':
	case '-':
		lhsP = 1;
		break;
	}
	//get rhs precedence
	switch (rhs) {
	case '*':
		rhsP = 2;
		break;
	case '/':
		rhsP = 2;
		break;
	case '+':
		rhsP = 1;
		break;
	case '-':
		rhsP = 1;
		break;
	}
	return lhsP > rhsP;
}

//infix to postfix
char * infixToPostfix(char * infix)
{
	double token;
	char result [strlen(infix)+1];
	int i = 0;
	//stack for the operators
	stackptr s = init_stack(s);
	while( (token = getNextOperator(infix)) != EOF)
	{
		//if it's an operator, do stuff
		if(token == '+' || token == '-' || token == '/' || token == '*')
		{
			//if stack is empty, push operator onto the stack
			if(isEmpty(s)) 
				push(s,token);
			//if TOS has higher precedence than token, pop token.
			//repeat until TOS doesn't have higer precedence, or until empty
			else
			{
				if (isHigherPrecedence( top(s),token))
				{
					while( !isEmpty(s) && isHigherPrecedence(top(s),token) )
					{
						result[i++] = pop(s);
						result[i++] = ' ';
					}
				}
				//else, push token onto the stack
				else
					push(s,token);
			}
		}
		//add the number to the result
		else 
		{	
			char * number_str = itoa(token);
			int str_ptr = 0;
			while(number_str[str_ptr] != 0)
				result[i++] = number_str[str_ptr++];
			result[i++] = ' ';
			
		}
	}
	//pop the stack and add the operators to the end of result
	while (!isEmpty(s))
	{
		result[i++] = pop(s);
		result[i++] = ' ';
	}
	result[i] = 0;
	return strdup(result);
}

//convert integer to string
char * itoa(double num)
{
	char buffer[50];
	sprintf(buffer,"%.10g",num);
	return strdup(buffer);
}

//take a valid postfix expression (the operators/operands are seperated by spaces)
//and return the result
double eval(char * exp)
{
	double token;
	stackptr s = init_stack(s);
	while( (token = getNextOperator(exp)) != EOF ) 
	{
		if (token == '+')
			push(s,pop(s) + pop(s));
		else if (token == '-')
		{
			double rhs = pop(s);
			double lhs = pop(s);
			push(s,lhs - rhs);
		}
		else if (token == '*')
			push(s,pop(s) * pop(s));
		else if (token == '/')
		{
			double rhs = pop(s);
			double lhs = pop(s);
			push(s,lhs / rhs);
		}
		//else, it's a number, and just push it
		else
			push(s,token);
	}
	return pop(s);
}	

