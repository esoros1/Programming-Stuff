#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

const int MAXIMUM = 1000000;



void fillPrimes(int * primes);



int main()
{
	unsigned long int result = 1;
	int primes [MAXIMUM+1];
	fillPrimes(primes);

	//calulate the toitent values
		
	printf("%ld\n",result-2);
}

//fill primes
void fillPrimes(int * primes)
{
	int i;
	for(i = 0; i < MAXIMUM+1; ++i)
		primes[i] = TRUE;
	for(i = 2; i < MAXIMUM+1; ++i)
	{
		if (primes[i] == TRUE)
		{
			int j;
			for(j = 2; i*j < MAXIMUM+1; ++j)
				primes[i*j] = FALSE;
		}
	}
}
