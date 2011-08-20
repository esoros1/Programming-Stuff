#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getword.h"

#define FALSE 0
#define TRUE 1

typedef struct node * nodeptr;

struct node
{
	char * word;
	nodeptr left;
	nodeptr right;
	int count;
	int lines_ptr;
	//lines on which the word appears
	int lines[50];
	
} typedef node;

static char * noise_words[] = {"a","is","the","and"};


nodeptr add(nodeptr n, char * s, int line)
{
	int check;
	//if null, initalize the new node
	if (n == NULL)
	{
		n = (nodeptr) malloc(sizeof(node));
		n->word = strdup(s);
		n->count = 1;
		n->left = n-> right = NULL;
		n->lines_ptr = 0;
		n->lines[n->lines_ptr] = line;
	}
	else if ( (check = strcmp(s,n->word)) == 0)
	{
		//word found, increment count
		n->count += 1;
		if(n->lines[n->lines_ptr] != line)
		{
			n->lines_ptr += 1;
			n->lines[n->lines_ptr] = line;
		}
	}
	else if ( check > 0)
	{
		//it is larger, go right
		n->right = add(n->right,s,line);
	}
	else //it's larger, og left
		n->left = add(n->left,s,line);
	return n;
}

void printtree(nodeptr n)
{
	if(n->left != NULL)
		printtree(n->left);

	printf("word: %s\ncount: %d\n",n->word,n->count);
	int ptr = 0;
	printf("Line Numbers: ");

	while(n->lines[ptr] != 0) 
		printf(" %d",n->lines[ptr++]);
	
	printf("\n\n");

	if(n->right != NULL)
		printtree(n->right);
}
 int isnoiseword(char * word)
 {
	int i;
	for(i = 0; i < 4; ++i)
	{
		if(strcmp(word,noise_words[i]) == 0)
			return TRUE;
	}
	return FALSE;
 }

#define MAXLINE 100
int main()
{
	char * word;
	char line [100];
	nodeptr tree = NULL;
	int line_count = 1;

	while( (getline(line,100)) > 0)
	{
		while(strcmp( (word = getnextword(line)),"") != 0)
		{
			if(! isnoiseword(word))
				tree = add(tree,word,line_count);
			free(word);
		}
		++line_count;
	}
	printtree(tree);
	
	
}



