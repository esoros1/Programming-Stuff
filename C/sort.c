#include <stdio.h>

int main(int argc, char ** argv)
{
	char ** words[argc-1];
	
	int i;
	for(i = 0; i < argc-1; ++i)
		words[i] = argv[i+i];
}
