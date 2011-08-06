import java.util.TreeSet;
import java.util.Arrays;
import java.util.Iterator;
import java.math.BigInteger;
public class Problem72
{
	public static final int MAX = 1000000;
	public static TreeSet<Integer> primes;

	public static void main(String [] args)
	{
		long start = System.currentTimeMillis();
		
		primes = new TreeSet<Integer>();
		//use the sieve of eratosthenes to generate the prime numbers under MAX
		 boolean [] nums = new boolean [MAX];
		 Arrays.fill(nums,true);
		 for(int i = 2; i < MAX; ++i)
		 {
			if(nums[i])
			{
				for(int j = 2; i*j < MAX; ++j)
				{
					nums[i*j] = false;
				}
			}
		 }
		
		for(int i = 2; i < MAX; ++i)
			if(nums[i])
				primes.add(i);

		long result = 0;
		for(int i = 1; i <= MAX; ++i)
			result += phi(i);
		System.out.println(result+1-2);
		System.out.println("Found in "+ (System.currentTimeMillis()-start)/1000f +" seconds");
	}
	//return the value of Euler's Totient function of n
	//it took me like 2 days to realize I was overflowing int, so it would return negative for really
	//large numbers
	public static long phi(long n)
	{
		long result = n;
		if (n == 1)
			return 1L;

		//if it is prime, than everything < n is coprime to n
		if(primes.contains((int)n))
			return n-1;
		//else, prime factorization
		else
		{
			int lastNum = -1;
			while( n != 1)
			{
				Iterator i = primes.iterator();
				int prime = (Integer)i.next();

				while(n % prime != 0)
					prime = (Integer)i.next();
				//check for duplicates
				if (lastNum != prime)
				{
					result *= prime -1;
					result /= prime;
					lastNum = prime;
				}
				n /= prime;
			}
		}		
		return result;
	}

}
