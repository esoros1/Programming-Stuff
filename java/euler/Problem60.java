import java.util.TreeSet;
import java.util.Iterator;

public class Problem60
{

	public static TreeSet<Integer> primes = new TreeSet<Integer>();
	
	public static void main(String [] args)
	{
		for(int i = 2; i < 10000; ++i)
			if (isPrime(i))
				primes.add(i);

		//basically, look for a pair of primes that work,
		//than look for a third, and fourth and fifth.
		//analogous to a recursive backtracking I guess
		Iterator num1Itor = primes.iterator();
		boolean found = false;
		while(num1Itor.hasNext() && !found)
		{
			int num1 = (Integer)num1Itor.next();
			Iterator num2Itor = primes.iterator();
			while(num2Itor.hasNext() && !found)
			{
				int num2 = (Integer)num2Itor.next();
				if(num2 > num1)
				{
					int [] nums = {num1,num2};
					if (allPrime(nums))
					{
						Iterator num3Itor = primes.iterator();
						while(num3Itor.hasNext() && !found)
						{
							int num3 = (Integer)num3Itor.next();
							if (num3 > num2)
							{
								nums = new int [3];
								nums[0] = num1; 
								nums[1] = num2;
								nums[2] = num3;
								if (allPrime(nums))
								{
									Iterator num4Itor = primes.iterator();
									while(num4Itor.hasNext() && !found)
									{	
										int num4 = (Integer)num4Itor.next();
										if (num4 > num3)
										{
											nums = new int [4];
											nums[0] = num1;
											nums[1] = num2;
											nums[2] = num3;
											nums[3] = num4;
											if (allPrime(nums))
											{
												Iterator num5Itor = primes.iterator();
												while(num5Itor.hasNext() && !found)
												{
													int num5 = (Integer)num5Itor.next();
													if (num5 > num4)
													{
														nums = new int [5];
														nums[0] = num1;
														nums[1] = num2;
														nums[2] = num3;
														nums[3] = num4;
														nums[4] = num5;
														if (allPrime(nums))
														{
															System.out.println(sumNums(nums));
															found = true;
														}
													}
												}	
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}		
	
	}

	public static int sumNums(int [] myNums)
	{
		int result = 0;
		for(int i = 0; i < myNums.length; ++i)
			result += myNums[i];
		return result;
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
	//do all nums concatinate to form primes?
	public static boolean allPrime(int [] nums)
	{
		for(int i = 0; i < nums.length; ++i)
		{
			for(int j = i+1; j < nums.length; ++j)
			{
				if ( !isPrime(concatNums(nums[i],nums[j])) || !isPrime(concatNums(nums[j],nums[i])) )
				{
					return false;
				}
			} 
		}
		return true;
	}

	//combine two ints. concatNums(30,4) = 304
	public static int concatNums(int i,int j)
	{
		int base = 1;
		int result = 0;
		do
		{
			result += (j % 10) * base;
			base *= 10;
			j /= 10;
		} while (j != 0);

		do
		{
			result += (i % 10) * base;
			base *= 10;
			i /= 10;
		} while (i != 0);
		return result;
	}
}
