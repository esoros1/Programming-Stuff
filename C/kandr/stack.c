#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
//initalize the node
nodeptr init_node(nodeptr n)
{
	n = (nodeptr) malloc(sizeof(node));
	n->next = NULL;
}
//initalize the stack
stackptr init_stack(stackptr s)
{
	s = (stackptr) malloc(sizeof(stack));
	s->tos = NULL;
}
//push something onto the stack
void push(stackptr s, double num)
{
	nodeptr temp = init_node(temp);
	temp->num = num;

	temp->next = s->tos;
	s->tos = temp;
	
}
//pop something from the top of the stack
double pop(stackptr s)
{
	if(s->tos == NULL)
		return -1;

	nodeptr temp = s->tos;
	double result = temp->num;

	s->tos = temp->next;	
	free(temp);

	return result;
}


void print(stackptr s)
{
	nodeptr n = s->tos;
	while(n) {
		printf("%g\n",n->num);
		n = n->next;
	}
}

