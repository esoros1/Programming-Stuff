import java.util.HashMap;
import java.util.HashSet;
public class Problem95
{
	public static HashMap<Integer,Integer> nums;

	public static void main(String [] args)
	{
		//precalculate the sum of the proper divisors
		nums = new HashMap<Integer,Integer>(1000000);
		for(int i = 1; i < 1000000; ++i)
			nums.put(i,sumDivisors(i));
		//brute force. 
		int resultLength = 0;
		int result = 0;
		for(int i = 12; i < 1000000; ++i)
		{
			HashSet<Integer> chain = new HashSet<Integer>();
			int next = i;
			int length = 0;
			while(!chain.contains(next) && next < 1000000)
			{
				chain.add(next);
				next = nums.get(next);
				++length;
			}
			//if amicable, see if it is longer
			if (i == next && length > resultLength )
			{
				resultLength = length;
				result = i;
			}
		}

		//result is the longest chain, go through again and find the smallest member
		HashSet<Integer> chain = new HashSet<Integer>();
		int next = result;			
		int smallest = next;
		while(!chain.contains(next) && next < 1000000)
		{
			if (next < smallest)					
				smallest = next;
			chain.add(next);
			next = nums.get(next);
		}
		
		System.out.println(smallest);
	}

	public static int sumDivisors(int num)
	{
		int result = 0;
		for(int i = 1; i <= (int)Math.sqrt(num); ++i)
		{
			if(num % i == 0)
			{
				result += i;
				if (i != 1 && num/i != i)
					result += num/i;
			}
		}
		return result;
	}
}
