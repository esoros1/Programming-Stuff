#include <vector>
#include <iostream>
#include <string>
#include <math.h>


bool isPrime(int);

int main()
{
	std::set<int> primes;

	for(int i = 1000; i < 10000; ++i)
		if(isPrime(i))
			primes.insert(i);
			
	std::set<int>::iterator i; 
	for(i = primes.begin(); i != primes.end(); ++i)
	{
		std::set<int>::iterator j = (i + 1);
	}

	
}


bool isPrime(int num)
{
	for(int i = 2; i < sqrt(num); ++i)
	{
		if ( num % i == 0)
			return false;
	}

	return true;
}
