import java.util.TreeSet;
import java.util.Iterator;
public class Problem49
{
	public static void main(String [] args)
	{
		TreeSet<Integer> nums = new TreeSet<Integer>();
		for(int i = 0; i < 10; ++i)
		{
			nums.add(i);
		}

		Iterator it = nums.iterator();
		while(it.hasNext())
		{
			System.out.println(it.next());
		}
	}
}
