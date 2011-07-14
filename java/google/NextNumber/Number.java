import java.util.HashMap;
import java.util.Map;
import java.util.Set;


public class Number
{
	public static void main(String [] args)
	{
		Map<Integer,Integer> m = countNums(115);
		
	}

	//returns a HashMap that maps the digits to the number of times
	//it appears in the number
	public static Map<Integer,Integer> countNums(int num)
	{

		Map<Integer,Integer> m = new HashMap<Integer,Integer>();
		while (num != 0)
		{
			//the number to put in the HashMap
			int temp = num % 10;
			Integer freq = m.get(temp);
			//count how many times each digit appears
			m.put(temp, (freq == null ? 1 : freq + 1));
			num = num/10;
		}
		return m;
	}

}
