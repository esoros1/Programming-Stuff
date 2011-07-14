import java.util.HashMap;
import java.util.HashSet;
public class Problem74
{
	public static void main(String [] args)
	{
		HashMap<Integer,Integer> facts = new HashMap<Integer,Integer>();
		facts.put(0,1);
		facts.put(1,1);
		facts.put(2,2);
		facts.put(3,6);
		facts.put(4,24);
		facts.put(5,120);
		facts.put(6,720);
		facts.put(7,5040);
		facts.put(8,40320);
		facts.put(9,362880);

		int result = 0;
		for(long i = 70; i < 1000000; ++i)
		{
			if (getChainLength(i,facts) == 60)
				result += 1;
		}
		System.out.println(result);
	}

	//get the length of a facorial chain
	public static int getChainLength(long n,HashMap<Integer,Integer> facts)
	{
		HashSet<Long> nums = new HashSet<Long>();
		int length = 0;
		do
		{
			nums.add(n);
			n = sumFactNum(n,facts);	
			++length;	
		} while (! nums.contains(n));
		return length;
	}


	//sum the factorial of the digits
	public static long sumFactNum(long n, HashMap<Integer,Integer> facts)
	{	
		long result = 0;
		while(n != 0)
		{
			result = result + facts.get((int)n % 10);
			n = n /10;
		}
		return result;
	}
}
