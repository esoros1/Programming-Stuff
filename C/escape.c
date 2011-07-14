#include <stdio.h>

void escape(char * s, char * t);

int main()
{
	int i, c;
	char buffer [100];
	i = 0;
	while( (c = getchar()) != EOF)
		buffer[i++] = c;
	printf("ECHO\n:%s\n","this\sis\satest");
}
