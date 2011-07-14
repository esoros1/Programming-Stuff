public class Card
{
	public int value;
	public char suit;

	public Card()
	{
		value = -1;
		suit = 'A';
	}

	//takes a String of length 2
	public Card(String s)
	{
		char val = s.charAt(0);
		int temp = val - '0';
		if(temp >= 2 && temp <= 9)
			value = temp;
		else if(val == 'T')
			value = 10;
		else if(val == 'J')
			value = 11;
		else if(val == 'Q')
			value = 12;
		else if(val == 'K')
			value = 13;
		else if(val == 'A')
			value = 14;

		suit = s.charAt(1);
		
	}

	public String toString()
	{
		return value + " "+suit;
	}
	
}
