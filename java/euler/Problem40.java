import java.lang.StringBuilder;









//a StringBuilder can append a String, which makes it more efficient than a String, 
//which is immutable
public class Problem40
{
	public static void main(String [] args)
	{
		StringBuilder result = new StringBuilder();
		int i = 1;
		while(result.length() <= 1000000)
		{
			result.append(String.valueOf(i++));
		}

		int answer = 1;
		for(int j = 1; j <= 1000000; j = j * 10)
			answer = answer * getDigit(result,j);
		System.out.println(answer);
	}

	//returns the nth digit
	//n >= 1
	public static int getDigit(StringBuilder num, int n)
	{
		return num.charAt(n-1)-'0';
	}
}
