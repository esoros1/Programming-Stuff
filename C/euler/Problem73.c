#include <stdio.h>

//return the GCF of two numbers
int getGCF(int rhs, int lhs)
{
	int greater, smaller;
	if (rhs >= lhs)
	{
		greater = rhs;
		smaller = lhs;
	}
	else
	{
		greater = lhs;
		smaller = rhs;
	}

	int factor = smaller;
	while(factor > 1)
	{
		if (smaller % factor == 0 && greater % factor == 0)
			return factor;
		--factor;
	}
	return factor;
}

int main()
{
	const int MAXIMUM = 12000;
	const double err = 0.0001;
	const double lower = (double)1 / (double)3;
	const double upper = (double)1/ (double)2;

	int i; 
	int result = 0;
	for(i = 2; i <= MAXIMUM; ++i)
	{
		printf("%d\n",i);
		int j;
		for(j = 1; j < MAXIMUM; ++j)
		{
			if (getGCF(j,i) == 1)
			{
				double temp = (float)j / (float)i;
				if (temp-err > lower && temp+err < upper)
				{
					++result;
				}
			}
		}
	}
	printf("%d\n",result);
}
