#include <stdio.h>
#define TRUE 1
#define FALSE 0

const int MAXIMUM = 1000000;

int main()
{
	//fill primes
	int primes [MAXIMUM];
	int i;
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

	int maxLength = 0;
	int prime = 0;
	//brute force. search each number while it is less than MAX
	for(i = 2; i < MAXIMUM; ++i)
	{
		if (primes[i] == TRUE)
		{
			int num = i;
			int temp = num;
			int numPrimes = 0;
			while(temp < MAXIMUM)
			{
				if(primes[++num] == TRUE)
				{
					temp += num;
					numPrimes++;
					if (temp < MAXIMUM && primes[temp] == TRUE)
					{
						if(numPrimes > maxLength)
						{
							prime = temp;
							maxLength = numPrimes;
						}
					}
				}
			}
		}
	}

	printf("Prime: %d Length: %d\n",prime,maxLength+1);
}
