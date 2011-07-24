import java.util.TreeSet;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.io.*;


public class Base
{

	public static final int MAX = 1000000;
	public static HashSet<String> happyNumsCalculated = new HashSet<String>();
	

	static String toBaseString(Integer n, int base)
	{
		return Integer.toString(n,base);
	}

	static int sumSquareDigitsString(String s)
	{
		int result = 0;
		for(int i = 0; i < s.length(); ++i)
			result += Math.pow( ((int)s.charAt(i) - (int)'0'),2);
		return result;
	}

	static boolean isHappy(Integer n, int base)
	{
		HashSet<String> nums = new HashSet<String>();
		LinkedList<String> cachedNums = new LinkedList<String>();
		//convert to the correct representation
		String number = toBaseString(n,base);
		boolean result = false;
		do
		{
			//check if the current number leads to a happy ending :)
			result =  happyNumsCalculated.contains(number);
			nums.add(number);
			cachedNums.add(number);
			number = toBaseString(sumSquareDigitsString(number),base);
		} while(!number.equals("1") && !nums.contains(number) && !result);

		if(result)
			return true;
		result = number.equals("1");
		if (result)
			happyNumsCalculated.add(number);
		return result;
		
	}

	public static void main(String [] args) throws IOException
	{
		//FILE IO
		BufferedReader in = new BufferedReader(new FileReader("test.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		
		//Map numbers to a treeset of numbers that are happy below MAX
		HashMap<Integer,TreeSet<Integer> > happyNums = new HashMap<Integer, TreeSet<Integer> >();
		for(int base = 2; base <= 10; ++base)
		{
			System.out.println("Precalculating: "+base);
			TreeSet<Integer> happy = new TreeSet<Integer>();
			for(int i = 2; i < MAX; ++i)
			{
				if (isHappy(i,base))
					happy.add(i);
			}
			happyNums.put(base,happy);
		}
		//the actual program		
		int cases = Integer.parseInt(in.readLine());
		for(int cas = 1; cas <= cases; ++cas)
		{
			String [] data = in.readLine().split(" ");
			int [] bases = new int [data.length];
			for(int i = 0; i < bases.length; ++i)
				bases[i] = Integer.parseInt(data[i]);
			
			
			int i = 1;
			boolean found = false;
			Iterator itor = happyNums.get(bases[0]).iterator();
			int number = (Integer)itor.next();
			while(itor.hasNext() && !found)
			{
				TreeSet<Integer> currentBase = happyNums.get(bases[i]);
				if(currentBase.contains(number))
				{
					found = (i == bases.length-1);
					if(!found)
					{
						++i;
					}
				}
				else
				{
					i = 1;
					number = (Integer)itor.next();
				}
			}
			out.write("Case #"+cas+": "+number+"\n");
		}
		out.close();
	}
}
