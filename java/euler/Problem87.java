import java.util.TreeSet;
import java.util.Iterator;
import java.util.HashSet;

public class Problem87
{
	public static final int MAX = 50000000;

	public static void main(String [] args)
	{
		//put all of the primes into a TreeSet
		TreeSet<Integer> primes = new TreeSet<Integer>();
		//check for repeats
		HashSet<Integer> nums = new HashSet<Integer>();

		for(int i = 2; i <= (int)Math.sqrt(MAX); ++i)
		{
			if (isPrime(i))
				primes.add(i);
		}

		int result = 0;
		Iterator iItor = primes.iterator();
		while (iItor.hasNext())
		{
			int i = (int)Math.pow((Integer)iItor.next(),2);
			if (i > MAX)
				break;
			Iterator jItor = primes.iterator();
			while(jItor.hasNext())
			{
				int j = (int)Math.pow((Integer)jItor.next(),3);
				Iterator kItor = primes.iterator();
				if (i+j > MAX)
					break;
				while(kItor.hasNext())
				{
					int k = (int)Math.pow((Integer)kItor.next(),4);
					if(i+j+k > MAX)
						break;
					if (!nums.contains(i+j+k))
					{
						result += 1;
						nums.add(i+j+k);
					}
				}
			}
		}
		System.out.println(result);
	}


	public static boolean isPrime(int n)
	{
		for(int i = 2; i <= (int)Math.sqrt(n); ++i)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}
}
