//A composite is a number containing at least two prime factors. For example, 15 = 3  5; 9 = 3 3; 12 = 2  2  3.
//
//There are ten composites below thirty containing precisely two, not necessarily distinct, prime factors: 4, 6, 9, 10, 14, 15, 21, 22, 25,  26.
//
//How many composite integers, n  108, have precisely two, not necessarily distinct, prime factors?



//Brute force solution: keep on multiplying two primes below MAXIMUM

#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM 100000000
#define TRUE 1
#define FALSE 0


int main()
{
	//fill primes
	int * primes  = malloc(MAXIMUM * sizeof(int));
	long i;
	long j;
	for(i = 0; i < MAXIMUM; ++i)
		primes[i] = TRUE;

	for(i = 2; i < MAXIMUM; ++i)
	{
		if(primes[i] == TRUE)
		{
			int j;
			for(j = 2; j *i < MAXIMUM; ++j)
				primes[i*j] = FALSE;
		}
	}
	
	printf("Done Precalculating\n");
	int result = 0;
	for(i = 2; i <= MAXIMUM/2; ++i)
	{
		if(primes[i])
		{
			for(j = i; i*j < MAXIMUM; ++j)
			{
				//the answer was getting really large, and overflowing
				if(primes[j] && i*j < MAXIMUM)
				{
					++result;
				}
			}
		}
	}
	printf("%d\n",result);
}
