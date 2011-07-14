import java.io.*;

public class Runner
{
	public static void main(String [] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("poker.txt"));
		int result = 0;
		for(int j = 0; j < 1000; ++j)
		{
			String [] data = in.readLine().split(" ");
			String [] cards = new String [5];
			for(int i = 0; i < 5; ++i)
			{
				cards[i] = data[i];
			}
			Hand a = new Hand(cards);

			for(int i = 0; i < 5; ++i)
			{
				cards[i] = data[i+5];
			}
			Hand b = new Hand(cards);
			if (a.won(b))
				++result;
		}
		System.out.println(result);
	}
}
