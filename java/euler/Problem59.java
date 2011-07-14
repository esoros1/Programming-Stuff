import java.io.*;
import java.util.ArrayList;

public class Problem59
{
	public static void main(String [] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("cipher1.txt"));
		//ArrayLists that hold the three lists of chars to be XOR'ed
		ArrayList<Integer> fst = new ArrayList<Integer>();
		ArrayList<Integer> snd = new ArrayList<Integer>();
		ArrayList<Integer> thd = new ArrayList<Integer>();

		ArrayList<Character> fstChar = new ArrayList<Character>();
		ArrayList<Character> sndChar = new ArrayList<Character>();
		ArrayList<Character> thdChar = new ArrayList<Character>();

		String alphabet = "qwertyuiopasdfghjklzxcvbnm";
		char [] chars = alphabet.toCharArray();
		



		//fill the three lists
		String [] data = in.readLine().split(",");
		int i = 0;
		for(String s: data)
		{
			Integer num = Integer.parseInt(s);
			if (i == 0)
				fst.add(num);
			if (i == 1)
				snd.add(num);
			if (i == 2)
				thd.add(num);
			i = (i+1) % 3;
		}

		//which ones work for the first list?		
		for(char c : chars)
		{
			if (validChar(fst,c))
				fstChar.add(c);
		}

		//which ones work for the second list?		
		for(char c : chars)
		{
			if (validChar(snd,c))
				sndChar.add(c);
		}

		//which ones work for the third list?		
		for(char c : chars)
		{
			if (validChar(thd,c))
				thdChar.add(c);
		}
		//First char == f or g
		System.out.println(fstChar);
		// second char == o,l,n
		System.out.println(sndChar);
		//third char == d
		System.out.println(thdChar);

		String message = "";
		for(String s : data)
			message += (char)Integer.parseInt(s);

		int answer = 0;
		for(char c : message(message,"god").toCharArray())
			answer += c;

		System.out.println(answer);
		

	}


	public static String message(String message, String key)
	{
		int i = 0;
		char [] keys = key.toCharArray();
		char [] messages = message.toCharArray();
		String result = "";
		for (char c : messages)
		{
			result +=( (char)(c ^ keys[i]));
			i = (i+1) % 3;
		}
		return result;
	}

	//if we xor all the values, are they all printable?
	public static boolean validChar(ArrayList<Integer> lst, char c)
	{
		for(int num : lst)
			if(!isPrintable(num ^ c))
				return false;
		return true;

	}
	//is the ascii printable
	public static boolean isPrintable(int c)
	{
		return c >= 32 && c <= 122;
	}
}
