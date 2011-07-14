import java.util.LinkedList;
import java.util.HashSet;

public class Problem44
{
	public static void main(String [] args)
	{
		
		LinkedList<Integer> nums = new LinkedList<Integer>();
		HashSet<Integer> pent = new HashSet<Integer>();

		//a linked with the first 100 pentagonal numbers
		int num = 1;
		int numAdd = 4;
		while(nums.size() <= 100)
		{
			nums.add(num);
			pent.add(num);
			num = num + numAdd;
			numAdd = numAdd + 3;
		}
		
		for(int i = 0; i < nums.size()-1; ++i)
		{
			for(int j = i + i; j < nums.size(); ++j)
			{
				if(pent.contains(num.get(i) + num.get(j)))
					System.out.println((num.get(i)) + num.get(j));
			}
		}

	}
}
