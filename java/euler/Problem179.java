
public class Problem179
{
	public static void main(String [] args)
	{
		int result = 0;
		for(int i = 2; i < 10000000; ++i)
		{
			if (i % 100000 == 0)
				System.out.println(i);
			if(hasSameDivisors(i,i+1))
				result += 1;
		}
		System.out.println(result);
	}


	public static boolean hasSameDivisors(int n, int m)
	{
		int numDivisorsN = 0;
		int i;
		for(i = 1; i <= (int)Math.sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				//check to see if it is a square
				if (n % i == 0 && Math.pow(i,2) != n)
					numDivisorsN += 2;
				else
					numDivisorsN += 1;
			}
		}


		//as soon as the second one has more divisors, we bail
		int numDivisorsM = 0;
		int j;
		for(j = 1; j <= (int)Math.sqrt(m); ++j)
		{
			if (m % j == 0)
			{
				if (m % j == 0 && Math.pow(j,2) != m)
					numDivisorsM += 2;
				else
					numDivisorsM += 1;
			}

			//check to see if we have to bail early
			if (numDivisorsM > numDivisorsN)
				return false;
		}
		return numDivisorsN == numDivisorsM;
	}

	//count the number of divisors
}
