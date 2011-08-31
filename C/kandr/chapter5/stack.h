#ifndef STACH_H
#define STACK_H

#define FALSE 0
#define TRUE 1

typedef struct stack * stackptr;
typedef struct node * nodeptr;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declarations for the node
struct node
{
	double num;
	nodeptr next;
} typedef node;

nodeptr init_node(nodeptr);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declarations for the stack
struct stack
{
	nodeptr tos;
} typedef stack;

stackptr init_stack(stackptr);
void push(stackptr,double);
double pop(stackptr s);
double top(stackptr s);
void print(stackptr);
int isEmpty(stackptr);

#endif
