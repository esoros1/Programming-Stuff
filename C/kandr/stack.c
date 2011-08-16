#include "calc.h"
#include <stdio.h>

#define MAXVALUE 100

int stack_pointer = 0;
double stack[100];

void push(double num)
{
	if(stack_pointer < (MAXVALUE - 1) ) 
		stack[stack_pointer++] = num;
	else
		printf("STACK OVERFLOW\n");
}

double pop()
{
	if(stack_pointer > 0)
		return stack[--stack_pointer];
	else
	{
		printf("STACK UNDERFLOW\n");
		return -1;
	}
}


