import java.util.TreeSet;
import java.util.Iterator;
import java.util.TreeMap;
import java.util.Set;

public class Problem51
{

	public static final int MAX = 1000000;
	public static TreeSet<Integer> primes;

	public static void main(String [] args)
	{
	    primes = new TreeSet<Integer>();

		boolean [] primesSieve = new boolean [MAX];
		for(int i = 0; i < MAX; ++i)
			primesSieve[i] = true;

		for(int i = 2; i < MAX; ++i)
		{
			if (primesSieve[i] == true)
			{
				for(int j = 2; i*j < MAX; ++j)
					primesSieve[i*j] = false;
			}
		}

		for(int i = 2; i < MAX; ++i)
		{	
			if (primesSieve[i] == true)
				primes.add(i);
		}

		Iterator i = primes.iterator();
		while(i.hasNext())
		{
			int num = (Integer)i.next();
			int temp = hasTwoDigits(num);
			if(temp <= 3)
				if(isNumPrimeFamily(replaceWithX(num,temp),8,num))
				{
					System.out.println(num);
					break;
				}
		}
	}

	//return the lowest digit that has more than two digits
	//if none, return 10;
	public static int hasTwoDigits(int num)
	{
		TreeMap<Integer,Integer> digits = new TreeMap<Integer,Integer>();

		while (num != 0)
		{
			int temp = num % 10;
			if (temp <= 2)
			{
				if (!digits.containsKey(temp))
					digits.put(temp,1);
				else
					digits.put(temp,digits.get(temp)+1);
			}
			num = num/10;
		}
		Iterator key = digits.keySet().iterator();
		while(key.hasNext())
		{
			int n = (Integer) key.next();
			if(digits.get(n) >= 2)
				return n;
		}
		return 10;
	}

	public static char itoa(int num)
	{
		return (char) (num+48);
	}

	//replace every occurance of digit in num with an x
	public static String replaceWithX(int num, int digit)
	{
		String result = Integer.valueOf(num).toString();
		return result.replace(itoa(digit),'x');
	}

	public static boolean isNumPrimeFamily(String num,int numPrime,int original)
	{
		int result = 0;
		for(int i = 0; i < 10; ++i)
		{
			int n = Integer.valueOf(num.replace('x',itoa(i)));
			{
				if (primes.contains(n) && n >= original)
				{
					//System.out.println(n);
					result += 1;
				}
			}
		}
		return result >= numPrime;
	}

}
