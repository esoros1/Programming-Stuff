import java.math.BigInteger;
import java.util.HashMap;

public class Problem104
{
	public static void main(String [] args)
	{
		BigInteger fst = BigInteger.ONE;
		BigInteger snd = BigInteger.ONE;

		BigInteger currentFib = BigInteger.ZERO;
		boolean found = false;

		int i = 3;
		while(!found)
		{
			currentFib  = fst.add(snd);
			//System.out.println(currentFib);
			fst = snd;
			snd = currentFib;
			if (i > 100)
			{
				String temp = currentFib.toString();
				String firstNine = temp.substring(0,9);
				String lastNine = temp.substring(temp.length()-9,temp.length());

				found =  isPandigital(lastNine) && isPandigital(firstNine);
			}
			++i;
			if (i % 10000 == 0)
				System.out.println(i);
		}

		System.out.println(i-1);
	}

	//does the string contain the digits 1-9????
	public static boolean isPandigital(String num)
	{
		HashMap <Character,Integer> digits = new HashMap<Character, Integer>(9);

		for(int i = 0; i < num.length(); ++i)
		{
			char check = num.charAt(i);
			if (digits.containsKey(check) || check == '0')
				return false;
			digits.put(check,1);
		}
		return true;
	}
}
