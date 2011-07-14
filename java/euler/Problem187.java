import java.util.TreeSet;
import java.util.Iterator;

public class Problem187
{
	public static final int MAX = 30;

	public static void main(String [] args)
	{
		TreeSet<Integer> primes = new TreeSet<Integer>();
		for(int i = 2; i <= (int)Math.sqrt(MAX); ++i)
			if (isPrime(i))
				primes.add(i);	

		Iterator itor = primes.iterator();
		while(itor.hasNext())
			System.out.println(itor.next());
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
