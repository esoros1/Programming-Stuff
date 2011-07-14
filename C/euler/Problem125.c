#include <stdio.h>
#include <math.h>
#define FALSE 0
#define TRUE 1

const int MAXIMUM = 100000000;


int isPalindromic(int num)
{
	
	int length = 0;
	int digits[50];
	while(num != 0)
	{
		digits[length++] = num % 10;
		num /= 10;
	}

	int i,j;
	for(i = 0, j = length-1; i < j; ++i,--j)
	{
		if(digits[i] != digits[j])
		{
			return FALSE;
		}
	}
	return TRUE;
}


int main()
{
	int i;
	long int result = 0;
	for(i = 1; i < (int)sqrt(MAXIMUM); ++i)
	{
		//printf("%d\n",i);
		int start = i;
		int sumOfSquares = 0;
		while(sumOfSquares < MAXIMUM)
		{
			sumOfSquares += pow(start,2);
			if (start != i && sumOfSquares < (MAXIMUM) && isPalindromic(sumOfSquares))
			{
				result += sumOfSquares;
			}
			start++;
		}
	}
	printf("%ld\n",result);
}


