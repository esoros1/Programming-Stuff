public class Problem112
{
	public static void main(String [] args)
	{
		long start = System.currentTimeMillis();

		long n = 1;
		int bouncy = 0;
		int total = 0;

		double percent = 0;
		while(percent < (99.0/100.0) )
		{
			if(isBouncy(n))
				bouncy += 1;
			total += 1;
			percent = (double)bouncy / (double)total;
			n += 1;
		}
		
		System.out.println( total );
		System.out.println("Found in "+ (System.currentTimeMillis() - start)/1000.0 +" seconds");
	}


	public static boolean isBouncy(long n)
	{
		if (n < 100)
			return false;
		char [] num = Long.toString(n).toCharArray();
		for(int i = 0; i < num.length-1; ++i)
		{
			if (num[i] < num[i+1])
				return !isIncreasing(num);
			if (num[i] > num[i+1])
				return !isDecreasing(num);
		}
		//if they are the same, than it is not bouncy
		return false;
	}

	public static boolean isDecreasing(char [] num)
	{
		for(int i = 0; i < num.length-1; ++i)
		{
			if(num[i] < num[i+1])
				return false;
		}
		return true;
	}

	public static boolean isIncreasing(char [] num)
	{
		for(int i = 0; i < num.length-1; ++i)
		{
			if(num[i] > num[i+1])
				return false;
		}
		return true;
	}


}
